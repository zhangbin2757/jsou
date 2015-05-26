/*
 * RpcChannel.cpp
 *
 *  Created on: May 26, 2015
 *      Author: zhangbin
 */

#include "RpcChannel.h"
#include "Mutex.hpp"
#include "Thread.hpp"

namespace jsou {

const size_t RpcChannel::PROTO_HDR_LEN_OFFSET = 0;
const size_t RpcChannel::PROTO_BODY_OFFSET = sizeof(proto_size_t);
const size_t RpcChannel::PROTO_BODY_MAX_SIZE = 4 * 1024;

class LoopRunnable : public Runnable {
public:
	LoopRunnable(RpcClientChannel *channel) : mChannel(channel){

	}
	void Run() {
		mChannel->mRunning = true;
		event_base_dispatch(mChannel->mBase);
		delete this;
	}
private:
	RpcClientChannel *mChannel;
};

RpcChannel::RpcChannel(struct event_base *base, log4cpp::Category &category) :
		mBase(base), mBev(0), mCategory(category), mBodySize(0) {

}

RpcChannel::~RpcChannel() {

}

void RpcChannel::SendMessage(const RpcMessage &message) {
	mCategory.debug("send message type = %d; id = %ul", message.type(),
			message.id());
	proto_size_t byteSize = message.ByteSize(), byteSizeBE = htons(byteSize);
	struct evbuffer *buffer = evbuffer_new();
	if (!evbuffer_expand(buffer, byteSize + PROTO_BODY_OFFSET)) {
		struct evbuffer_iovec vec;
		if (evbuffer_reserve_space(buffer, byteSize + PROTO_BODY_OFFSET, &vec,
				1) == 1) {
			uint8_t *start = static_cast<uint8_t*>(vec.iov_base);
			memcpy(start, &byteSizeBE, sizeof(byteSizeBE));
			uint8_t *end = message.SerializeWithCachedSizesToArray(
					start + PROTO_BODY_OFFSET);
			if (end - (start + PROTO_BODY_OFFSET) == byteSize) {
				vec.iov_len = byteSize + PROTO_BODY_OFFSET;
				evbuffer_commit_space(buffer, &vec, 1);
				evbuffer_add_buffer(bufferevent_get_output(mBev), buffer);
			} else {
				mCategory.error(
						"serialize message with cached size occur a error...");
			}
		} else {
			mCategory.error("some error in reserve space...");
		}
	} else {
		mCategory.error("expand %d buffer failed...",
				byteSize + PROTO_BODY_OFFSET);
	}
	evbuffer_free(buffer);
}

void RpcChannel::OnRead() {
	struct evbuffer *input = bufferevent_get_input(mBev);
	if (mBodySize > 0) {
		if (evbuffer_get_length(input) >= (size_t) mBodySize) {
			RpcMessage message;
			if (message.ParseFromArray(evbuffer_pullup(input, mBodySize),
					mBodySize)) {
				OnMessage(message);
			} else {
				//INTERNAL ERROR
			}
			evbuffer_drain(input, mBodySize);
			mBodySize = 0;
			bufferevent_setwatermark(mBev, EV_READ, PROTO_BODY_OFFSET, 0);
		}
	} else if (mBodySize == 0) {
		if (evbuffer_get_length(input) >= (size_t) PROTO_BODY_OFFSET) {
			proto_size_t bodySizeBE;
			if (evbuffer_remove(input, &bodySizeBE, sizeof(proto_size_t))
					== sizeof(proto_size_t)) {
				mBodySize = ntohs(bodySizeBE);
				if (mBodySize > 0) {
					if (evbuffer_get_length(input) >= (size_t) mBodySize) {
						OnRead();
					} else {
						bufferevent_setwatermark(mBev, EV_READ, mBodySize, 0);
					}
				} else {
					//PROTO ERROR
				}
			}
		}
	}
}

void RpcChannel::bufferevent_read_cb(struct bufferevent *bev, void *ctx) {
	RpcChannel *jrc = static_cast<RpcChannel*>(ctx);
	jrc->OnRead();
}

void RpcChannel::bufferevent_event_cb(struct bufferevent *bev, short what,
		void *ctx) {
	RpcChannel *jrc = static_cast<RpcChannel*>(ctx);
	if (what & (BEV_EVENT_EOF | BEV_EVENT_ERROR)) {
		jrc->OnDisconnect();
	} else if (what & BEV_EVENT_CONNECTED) {
		jrc->OnConnect();
	}
}

RpcClientChannel::RpcClientChannel(log4cpp::Category &category,
		const string &host, const int &port) :
		jsou::RpcChannel(event_base_new(), category), mID(0), mRunning(false) {
	mMutex = new Mutex;
	mBev = bufferevent_socket_new(mBase, -1, BEV_OPT_CLOSE_ON_FREE);
	bufferevent_setwatermark(mBev, EV_READ, PROTO_BODY_OFFSET, 0);
	bufferevent_setcb(mBev, bufferevent_read_cb, 0, bufferevent_event_cb, this);
	bufferevent_socket_connect_hostname(mBev, 0, AF_INET, host.c_str(), port);

}

RpcClientChannel::~RpcClientChannel() {
	bufferevent_free(mBev);
	delete mMutex;
}

void RpcClientChannel::Start() {
	if (!mRunning) {
		mThread = new Thread(new LoopRunnable(this));
		mThread->Start();
	}
}

void RpcClientChannel::Stop() {
	if (mRunning) {
		struct timeval tv;
		evutil_timerclear(&tv);
		tv.tv_sec = 2;
		event_base_loopexit(mBase, &tv);
		mThread->Join();
		delete mThread;
		mRunning = false;
	}
}

void RpcClientChannel::OnMessage(const RpcMessage &message) {
	MType type = message.type();
	uint64_t id = message.id();
	mCategory.debug("receive a message type = %d; id = %lu", type, id);
	mMutex->Lock();
	map<uint64_t, PendingCall*>::iterator iter = mPendingCalls.find(id);
	if (iter != mPendingCalls.end()) {
		PendingCall *pc = (*iter).second;
		mPendingCalls.erase(iter);
		if (type == RESPONSE) {
			if (pc->response) {
				pc->response->ParseFromString(message.response());
			}
		} else if (type == ERROR) {
			mCategory.error("error code = %d", message.code());
		}
		if (pc->done) {
			pc->done->Run();
		}
	}
	mMutex->UnLock();
}

void RpcClientChannel::CallMethod(const gpb::MethodDescriptor* method,
		gpb::RpcController* controller, const gpb::Message* request,
		gpb::Message* response, gpb::Closure* done) {
	PendingCall *pc = new PendingCall;
	pc->response = response;
	pc->done = done;
	RpcMessage message;
	message.set_type(REQUEST);
	if (request) {
		message.set_request(request->SerializeAsString());
	}
	mMutex->Lock();
	message.set_id(mID);
	mPendingCalls[mID++] = pc;
	mMutex->UnLock();
	message.set_servicename(method->service()->full_name());
	SendMessage(message);
}

void RpcClientChannel::OnConnect() {
	bufferevent_setwatermark(mBev, EV_READ, PROTO_BODY_OFFSET, 0);
	bufferevent_enable(mBev, EV_READ | EV_WRITE);
}

RpcServerChannel::RpcServerChannel(struct event_base *base,
		log4cpp::Category &category,
		evutil_socket_t sock, map<string, gpb::Service*> &services) :
		RpcChannel(base, category), mServices(services) {
	mBev = bufferevent_socket_new(base, sock, BEV_OPT_CLOSE_ON_FREE);
	bufferevent_setwatermark(mBev, EV_READ, PROTO_BODY_OFFSET, 0);
	bufferevent_setcb(mBev, bufferevent_read_cb, 0, bufferevent_event_cb, this);
	bufferevent_enable(mBev, EV_READ | EV_WRITE);
}

RpcServerChannel::~RpcServerChannel() {
	bufferevent_free(mBev);
}

void RpcServerChannel::OnMessage(const RpcMessage &message) {
	if (message.type() == REQUEST) {
		if (message.has_servicename()) {
			mCategory.debug("remote call service = %s;",
					message.servicename().c_str());
			map<string, gpb::Service*>::iterator iter = mServices.find(
					message.servicename());
			if (iter != mServices.end()) {
				gpb::Service *service = (*iter).second;
				const gpb::MethodDescriptor *md =
						service->GetDescriptor()->method(0);
				if (md) {
					mCategory.debug("find the service %s method %s success;",
							message.servicename().c_str(),
							md->full_name().c_str());
					gpb::Message *request =
							service->GetRequestPrototype(md).New();
					if (message.has_request()) {
						if (!request->ParseFromString(message.request())) {
							RpcMessage message;
							message.set_type(ERROR);
							message.set_code(INVALID_REQUEST);
							SendMessage(message);
							delete request;
						}
					}
					gpb::Message *response =
							service->GetResponsePrototype(md).New();
					service->CallMethod(md, 0, request, response,
							NewCallback(this, &RpcServerChannel::OnDone,
									response, message.id()));
					delete request;
				}
			} else {
				//NO_SERVICE
				RpcMessage message;
				message.set_type(ERROR);
				message.set_code(NO_SERVICE);
				SendMessage(message);
			}
		} else {
			//INVALID PROTO
			RpcMessage message;
			message.set_type(ERROR);
			message.set_code(WRONG_PROTO);
			SendMessage(message);
		}
	}
}

void RpcServerChannel::OnDone(gpb::Message *response, uint64_t id) {
	RpcMessage message;
	message.set_type(RESPONSE);
	message.set_id(id);
	message.set_response(response->SerializeAsString());
	SendMessage(message);
	delete response;
}

void RpcServerChannel::OnDisconnect() {
	mCategory.debug("ready to close the socket %d", bufferevent_getfd(mBev));
	delete this;
}

}
