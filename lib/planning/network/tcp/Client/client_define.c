#include "client_define.h"

HW_INT CreateClient(HW_INT argc, HW_CHAR const *argv[])
{
    ASSERT_NOT_EQUEL_RETERR(argc, MAIN_ARG_NUM3);
    HW_INT ret = SUCC;
    HW_INT cltSockId = 0;
    // 设置一个socket地址结构client_addr, 代表客户机的internet地址和端口
    struct sockaddr_in cltAddr, servAddr;
    bzero(&cltAddr, sizeof(cltAddr));
    bzero(&servAddr, sizeof(servAddr));
    cltAddr.sin_family = AF_INET; // internet协议族
    cltAddr.sin_addr.s_addr = htons(INADDR_ANY); // INADDR_ANY表示自动获取本机地址
    cltAddr.sin_port = htons(0); // auto allocated, 让系统自动分配一个空闲端口
    SOCKET(cltSockId);
    servAddr.sin_family = AF_INET;
    BIND(cltSockId, cltAddr, sizeof(cltAddr));
        // 服务器的IP地址来自程序的参数
    if (0 == inet_aton(argv[1], &servAddr.sin_addr))
    {
        HWPP_LOG_ERR("Server IP Address Error!\n");
        return GENERAL_ERR;
    }
    servAddr.sin_port = htons(SERVER_PORT);
    socklen_t servAddrLen = sizeof(servAddr);
    CONNECT(ret, cltSockId, servAddr, servAddrLen);
    HW_CHAR buf[BUFSIZE_128BYTE] = {0};
    HW_CHAR* fileName = NULL;
    HW_INT fileNameLen = 0;
    HW_INT sendLen = 0;
    HW_INT recvLen = 0;
    HW_INT writeLen = 0;
    FILE* fp = NULL;
    STRDUP_ERR_BREAK(fileNameLen, &fileName, argv[2]);
    SEND(sendLen, cltSockId, fileName, fileNameLen);
    FOPEN_ERR_BREAK(fp, fileName, ONLY_WRITE);
    while(recvLen = recv(cltSockId, buf, sizeof(buf), 0) > 0) {
        writeLen = fwrite(buf, sizeof(HW_CHAR), BUFSIZE_128BYTE, fp);
        if(0 > writeLen) {
            HWPP_LOG_ERR("fwrite error.%s:%d", writeLen);
            return GENERAL_ERR;
        }
        bzero(&buf, sizeof(buf));
    }
    freePtr(fileName);
    close(cltSockId);
}
