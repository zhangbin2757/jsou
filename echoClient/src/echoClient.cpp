//============================================================================
// Name        : echoClient.cpp
// Author      : zhangbin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "RpcChannel.h"
#include "proto/echo.pb.h"
#include "proto/service.pb.h"

#include <unistd.h>

void done(jsou::Response *response, jsou::RpcClientChannel *channel) {
	if(response->has_response()) {
		echo::EchoRes echoRes;
		echoRes.ParseFromString(response->response());
		std::cout << "type = " << echoRes.type() << "; response = " << echoRes.res() << endl;
	}
	delete response;
	channel->Stop();
}

int main() {
    log4cpp::PropertyConfigurator::configure("./log4cpp.conf");
    log4cpp::Category &mLog = log4cpp::Category::getInstance("sub1");
    jsou::RpcClientChannel *channel = new jsou::RpcClientChannel(mLog, "172.16.132.55", 8088);
    channel->Start();
    jsou::JsouService::Stub echo_stub(channel);
    jsou::Request request;
    echo::EchoReq echoRequest;
    echoRequest.set_type(echo::ECHO);
    echoRequest.set_req("hello world !!!");
    request.set_request(echoRequest.SerializeAsString());
    jsou::Response *response = new jsou::Response;
    echo_stub.Call(0, &request, response, NewCallback(done, response, channel));
    sleep(3);
	return 0;
}
