/*
 * RpcChannel.h
 *
 *  Created on: May 26, 2015
 *      Author: zhangbin
 */

#ifndef RPCCHANNEL_H_
#define RPCCHANNEL_H_

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/util.h>

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>

#include "proto/rpc.pb.h"

#include <map>

using namespace std;

namespace gpb = google::protobuf;

namespace jsou {
class Mutex;
class Thread;
class Runnable;
class LoopRunnable;
class RpcChannel {
public:
	RpcChannel(struct event_base *base, log4cpp::Category &log);
	virtual ~RpcChannel();
protected:
	virtual void OnMessage(const RpcMessage &message) = 0;
	void SendMessage(const RpcMessage &message);
	virtual void OnConnect() {
	}
	virtual void OnDisconnect() {
	}
	void OnRead();
	static void bufferevent_read_cb(struct bufferevent *bev, void *ctx);
	static void bufferevent_event_cb(struct bufferevent *bev, short what,
			void *ctx);
protected:
	struct event_base *mBase;
	struct bufferevent *mBev;
	log4cpp::Category &mCategory;
	int mBodySize;
	static const size_t PROTO_HDR_LEN_OFFSET;
	static const size_t PROTO_BODY_OFFSET;
	static const size_t PROTO_BODY_MAX_SIZE;
	typedef short proto_size_t;
};

class RpcClientChannel: public jsou::RpcChannel, public gpb::RpcChannel {
	friend class LoopRunnable;
	struct PendingCall {
		gpb::Message* response;
		gpb::Closure* done;
	};
public:
	RpcClientChannel(log4cpp::Category &category,
			const string &host, const int &port);
	~RpcClientChannel();
	void Start();
	void Stop();
protected:
	void OnMessage(const RpcMessage &message);
	void CallMethod(const gpb::MethodDescriptor* method,
			gpb::RpcController* controller, const gpb::Message* request,
			gpb::Message* response, gpb::Closure* done);
	void OnConnect();
private:
	uint64_t mID;
	Mutex *mMutex;
	bool mRunning;
	map<uint64_t, PendingCall*> mPendingCalls;
	Thread *mThread;
	Runnable *mLoopTask;
};

class RpcServerChannel: public RpcChannel {
public:
	RpcServerChannel(struct event_base *base, log4cpp::Category &log,
	evutil_socket_t sock, map<string, gpb::Service*> &services);
	~RpcServerChannel();
protected:
	void OnMessage(const RpcMessage &message);
	void OnDone(gpb::Message *response, uint64_t id);
	void OnDisconnect();
private:
	map<string, gpb::Service*> &mServices;
};
}

#endif /* RPCCHANNEL_H_ */
