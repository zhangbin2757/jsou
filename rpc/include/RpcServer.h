/*
 * RpcServer.h
 *
 *  Created on: May 26, 2015
 *      Author: zhangbin
 */

#ifndef RPCSERVER_H_
#define RPCSERVER_H_

#include "RpcChannel.h"

#include <event2/listener.h>

namespace jsou {

class RpcServer {
public:
	RpcServer(log4cpp::Category &category);
	virtual ~RpcServer();
	void Start(int port);
	void Stop();
	void Register(gpb::Service *service);
	inline bool IsRunning() {
		return mRunning;
	}
	inline struct event_base* getEvBase() {
		return mBase;
	}
private:
	void OnConnect(evutil_socket_t sock);
	static void evconnlistener_cb(struct evconnlistener *listener,
	evutil_socket_t sock, struct sockaddr *addr, int socklen, void *user_arg);
	static void evconnlistener_error_cb(struct evconnlistener *listener,
			void *user_arg);
private:
	log4cpp::Category &mCategory;
	struct event_base *mBase;
	struct evconnlistener *mConnListener;
	bool mRunning;
	map<string, gpb::Service*> mServices;
};


}

#endif /* RPCSERVER_H_ */
