/*
 * EchoServiceImpl.hpp
 *
 *  Created on: May 26, 2015
 *      Author: zhangbin
 */

#ifndef ECHOSERVICEIMPL_HPP_
#define ECHOSERVICEIMPL_HPP_

#include "proto/rpc.pb.h"
#include "proto/service.pb.h"
#include "proto/echo.pb.h"

#include <iostream>

namespace echo {

	class EchoServiceImpl : public jsou::JsouService {
	public:
		void Call(::google::protobuf::RpcController* controller,
		                       const ::jsou::Request* request,
		                       ::jsou::Response* response,
		                       ::google::protobuf::Closure* done) {
			EchoReq echoReq;
			if(request->has_request()) {
				echoReq.ParseFromString(request->request());
				std::cout << "type = " << echoReq.type() << "; request = " << echoReq.req() << std::endl;
				EchoRes echoRes;
				echoRes.set_type(echoReq.type());
				echoRes.set_res(echoReq.req());
				response->set_response(echoRes.SerializeAsString());
				if(done) {
					done->Run();
				}
			}
		}
	};

}

#endif /* ECHOSERVICEIMPL_HPP_ */
