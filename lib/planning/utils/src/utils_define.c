#include "pub_define.h"

HW_VOID
HwLog(HW_CHAR* positionInfo, const HW_CHAR* fmt, ...)
{
    do {
        HW_CHAR timeBuf[BUFSIZE_24BYTE] = { 0 };
        HW_CHAR printBuf[BUFSIZE_128BYTE] = { 0 };
        HW_CHAR* inputBuf = NULL;
        HW_UINT inputBufLen = 0;
        FILE* fp = NULL;
        time_t t = time(NULL);
        struct tm* lt = localtime(&t);
        strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", lt);
        if (NULL == timeBuf) {
#if LOG_STATUS > LOG_OPEN_LV1
            printf("%d-%d-%d %d:%d:%d %s timeBuf  is null.\n",
                lt->tm_year + 1900,
                lt->tm_mon + 1,
                lt->tm_mday,
                lt->tm_hour,
                lt->tm_min,
                lt->tm_sec,
                positionInfo);
#endif
            break;
        }
        va_list args;
        va_start(args, fmt);
        vsnprintf(printBuf, sizeof(printBuf), fmt, args);
        va_end(args);
        if (NULL == printBuf) {
#if LOG_STATUS > LOG_CLOSE
            printf("%s %s printBuf is null.\n", timeBuf, positionInfo);
#endif
            break;
        }
        fp = fopen(LOGPATH, "at+");
        if (NULL == fp) {
#if LOG_STATUS > LOG_CLOSE
            printf("%s %s fopen failed.\n", timeBuf, positionInfo);
#endif
            break;
        }
        inputBufLen = strlen(timeBuf) + strlen(printBuf) + strlen(positionInfo) + BUFSIZE_128BYTE;
        inputBuf = (HW_CHAR*)malloc(inputBufLen * sizeof(HW_CHAR));
        if (NULL == inputBuf) {
#if LOG_STATUS > LOG_OPEN_LV1
            printf("%s %s malloc failed.\n", timeBuf, positionInfo);
#endif
            break;
        }
        memset(inputBuf, 0, (inputBufLen * sizeof(HW_CHAR)));
        HW_INT fmtLen = snprintf(inputBuf,
            (inputBufLen * sizeof(HW_CHAR)),
            "%s %s%s\n",
            timeBuf,
            positionInfo,
            printBuf);

        if (NULL == inputBuf || (fmtLen > inputBufLen)) {
#if LOG_STATUS > LOG_CLOSE
            printf("%s %s snprintf failed.fmtLen:%d inputBufLen:%u.\n",
                timeBuf,
                positionInfo,
                fmtLen,
                inputBufLen);
#endif
            break;
        }
#if LOG_STATUS > LOG_CLOSE
        printf("%s", inputBuf);
#endif
        fwrite(inputBuf, strlen(inputBuf), 1, fp);
        freePtr(inputBuf);
        fclose(fp);
    } while (0);
    return;
}
