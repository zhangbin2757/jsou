//============================================================================
// Name        : echoService.cpp
// Author      : zhangbin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "RpcServer.h"
#include "EchoServiceImpl.hpp"

int main() {
    log4cpp::PropertyConfigurator::configure("./log4cpp.conf");
    log4cpp::Category &mLog = log4cpp::Category::getInstance("sub1");
	jsou::RpcServer rpcServer(mLog);
	echo::EchoServiceImpl *echoServiceImpl = new echo::EchoServiceImpl;
	rpcServer.Register(echoServiceImpl);
	rpcServer.Start(8088);
	delete echoServiceImpl;
	return 0;
}
