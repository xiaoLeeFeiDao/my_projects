#ifndef __SERVER_DEFINE_H_
#define __SERVER_DEFINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "pub_define.h"
#include "server_define.h"
#include "hwpp_util_log.h"

#define SERVER_IP "172.0.0.1"
#define CLIENT_IP "172.0.0.1"
#define SERVER_PORT 6666
#define CLINET_PORT 8888
#define LISTEN_QUEUE_SIZE 20

#define SOCKET(serverSockId) do {\
    serverSockId = socket(PF_INET, SOCK_STREAM, 0);\
    if(0 > serverSockId) {\
        HWPP_FPRINTF();\
        return GENERAL_ERR;\
    }\
}while(0)

#define BIND(serverSockId, serverAddr, serverAddrLen) do {\
    if(bind(serverSockId, (struct sockaddr*)&serverAddr, serverAddrLen)) {\
        HWPP_FPRINTF();\
        return GENERAL_ERR;\
    }\
}while(0)

#define LISTEN(serverSockId) do {\
    if(listen(serverSockId, LISTEN_QUEUE_SIZE)) {\
        HWPP_FPRINTF();\
        return GENERAL_ERR;\
    }\
}while(0)

#define ACCEPT(cltSockId, serverSockId, cltAddr, cltAddrLen) do {\
    cltSockId = accept(serverSockId, (struct sockaddr*)&cltAddr, &cltAddrLen);\
    if(0 > cltSockId) {\
        HWPP_FPRINTF();\
        return GENERAL_ERR;\
    }\
}while(0)

#define RECV(recvLen, cltSockId, recvBuf, recvBufLen) do {\
    recvLen = recv(cltSockId, recvBuf, recvBufLen, 0);\
    if(0 > recvLen) {\
        HWPP_FPRINTF();\
        return GENERAL_ERR;\
    }\
}while(0)

#define SEND(sendLen, cltSockId, sendBuf, sendBufLen) do {\
    sendLen = send(cltSockId, sendBuf, sendBufLen, 0);\
    if(0 > sendLen) {\
        HWPP_FPRINTF();\
        return GENERAL_ERR;\
    }\
}while(0)
HW_INT CreatServer();
#endif
