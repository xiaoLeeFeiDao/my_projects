#include "server_main.h"

HW_INT CreatServer()
{
    HW_INT servSockId = 0, cltSockId = 0;
    struct sockaddr_in servAddr, cltAddr;
    bzero(&servAddr, sizeof(servAddr));
    bzero(&cltAddr, sizeof(cltAddr));
    socklen_t servAddrLen = sizeof(servAddr);
    socklen_t cltAddrLen = sizeof(cltAddr);
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htons(INADDR_ANY);
    servAddr.sin_port = htons(SERVER_PORT);

    SOCKET(servSockId);
    BIND(servSockId, servAddr, servAddrLen);
    LISTEN(servSockId);

    HW_CHAR buf[BUFSIZE_128BYTE] = {0};
    HW_CHAR* fileName = NULL;
    HW_INT fileNameLen = 0;
    ssize_t recvLen = 0;
    ssize_t sendLen = 0;
    size_t fileBlkLen = 0;
    FILE* fp = NULL;
    while(TURE) {
        ACCEPT(cltSockId, servSockId, cltAddr, cltAddrLen);
        RECV(recvLen, cltSockId, buf, sizeof(buf));
        STRDUP_ERR_BREAK(fileNameLen, &fileName, buf);
        FOPEN_ERR_BREAK(fp, fileName, ONLY_READ);
        bzero(buf, sizeof(buf));
        fileBlkLen = fread(buf, sizeof(HW_CHAR), BUFSIZE_128BYTE, fp);
        while(0 < fileBlkLen) {
            HWPP_LOG_INFO("buf:%s fileBlklen:%lu", buf, fileBlkLen);
            SEND(sendLen, cltSockId, buf, fileBlkLen);
            bzero(buf, sizeof(buf));
        }
        FCLOSE_ERR_BREAK(fp);
        HWPP_LOG_INFO("File:\t%s Transfer Finished!\n", fileName);
    }
    freePtr(fileName);
    close(servSockId);
    close(cltSockId);
}
