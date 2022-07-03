#ifndef __CLIENT_DEFINE_H_
#define __CLIENT_DEFINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "pub_define.h"
#include "server_define.h"
#include "hwpp_util_log.h"
#include "operate_file.h"

#define CONNECT(ret, cltSockId, servAddr, servAddrLen) do {\
    ret = connect(cltSockId, (struct sockaddr*)&servAddr, servAddrLen);\
    if(0 > ret) {\
        HWPP_FPRINTF();\
        return GENERAL_ERR;\
    }\
}while(0)
HW_INT CreateClient(HW_INT argc, HW_CHAR const *argv[]);

#endif
