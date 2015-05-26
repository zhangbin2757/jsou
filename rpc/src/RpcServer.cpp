/*
 * RpcServer.cpp
 *
 *  Created on: May 26, 2015
 *      Author: zhangbin
 */

#include "RpcServer.h"
#include <event2/listener.h>

namespace jsou {

RpcServer::RpcServer(log4cpp::Category &category) :
		mCategory(category), mConnListener(0), mRunning(false) {
	mBase = event_base_new();
}

RpcServer::~RpcServer() {
	event_base_free(mBase);
}

void RpcServer::Start(int port) {
	mCategory.debug("start RpcServer mRunning = %d; bind port %d", mRunning,
			port);
	if (!mRunning) {
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = htonl(INADDR_ANY);
		addr.sin_port = htons(port);
		mConnListener = evconnlistener_new_bind(mBase, evconnlistener_cb, this,
		LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE, 512,
				(struct sockaddr*) (&addr), sizeof(addr));
		if (mConnListener) {
			evconnlistener_set_error_cb(mConnListener, evconnlistener_error_cb);
		}
		mRunning = true;
		event_base_dispatch(mBase);
	}
}

void RpcServer::Stop() {
	mCategory.debug("stop RpcServer mRunning = %d", mRunning);
	if (mRunning) {
		evconnlistener_free(mConnListener);
		struct timeval tv;
		evutil_timerclear(&tv);
		tv.tv_sec = 2;
		event_base_loopexit(mBase, &tv);
		mRunning = false;
	}
}

void RpcServer::Register(gpb::Service *service) {
	if (service) {
		mCategory.debug("register a service %s",
				service->GetDescriptor()->full_name().c_str());
		mServices[service->GetDescriptor()->full_name()] = service;
	}
}

void RpcServer::evconnlistener_cb(struct evconnlistener *listener,
evutil_socket_t sock, struct sockaddr *addr, int socklen, void *user_arg) {
	evutil_make_socket_nonblocking(sock);
	RpcServer *jrs = static_cast<RpcServer*>(user_arg);
	jrs->OnConnect(sock);
}

void RpcServer::evconnlistener_error_cb(struct evconnlistener *listener,
		void *user_arg) {
	RpcServer *jrs = static_cast<RpcServer*>(user_arg);
	jrs->Stop();
}

void RpcServer::OnConnect(evutil_socket_t sock) {
	mCategory.debug("a new socket connection coming");
	new RpcServerChannel(mBase, mCategory, sock, mServices);
}

}
