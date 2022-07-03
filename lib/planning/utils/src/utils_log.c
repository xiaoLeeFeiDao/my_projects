#include "hwpp_util_log.h"

/* void HwRecodeLongLog(HW_CHAR* format, ...)
{
    HW_INT ret = 0;
    FILE* fp = NULL;
    HW_CHAR* printBuf = NULL;
    size_t spaceSize = HwOsStrlen(format);
    printBuf = HwOsMallocByteInit(spaceSize, 0);
    ASSERT_NULL_PTR_RETVOID(printBuf);
    va_list args;
    va_start(args, format);
    ret = vsnprintf(printBuf, sizeof(printBuf), format, args);
    va_end(args);
    fp = fopen(LOGPATH, "at+");
    ASSERT_NULL_PTR_RETVOID(fp);
    //fwrite(printBuf, sizeof(printBuf), 1, fp);
#ifdef LOG_STATUS
    // HW_INT fd = open(LOGPATH, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    printf("%s\n", printBuf);
#endif
    fclose(fp);
    return;
}
void HwRecodeLogLengthHalfKB(HW_CHAR* format, ...)
{
    HW_INT ret = 0;
    FILE* fp = NULL;
    HW_CHAR printBuf[BUFSIZE_HALF_KB] = {0};
    va_list args;
    va_start(args, format);
    ret = vsnprintf(printBuf, sizeof(printBuf), format, args);
    va_end(args);
#if LOG_STATUS == 1
    printf("%s\n", printBuf);
#endif
    fp = fopen(LOGPATH, "at+");
    ASSERT_NULL_PTR_RETVOID(fp);
    fwrite(printBuf, sizeof(printBuf), 1, fp);
    fclose(fp);
    return;
}
void HwLog(HW_CHAR* printStr, HW_UINT logLevel)
{
    HW_CHAR* nowTime = GetLocalTimeDevColonYMDHMS();
    ASSERT_NULL_PTR_RETVOID(nowTime);
    switch (logLevel)
    {
    case INFO:
        HwRecodeLogLengthHalfKB("%s [fun: %s line: %d] --> %s:%s",
            nowTime, __FUNCTION__, __LINE__, TYPEINFO, printStr);
        break;
    case WARN:
        HwRecodeLogLengthHalfKB("%s [fun: %s line: %d] --> %s:%s",
            nowTime, __FUNCTION__, __LINE__, TYPEWARN, printStr);
        break;
    case DEBUG:
        HwRecodeLogLengthHalfKB("%s [fun: %s line: %d] --> %s:%s",
            nowTime, __FUNCTION__, __LINE__, TYPEDEBUG, printStr);
        break;
    case ERR:
        HwRecodeLogLengthHalfKB("%s [fun: %s line: %d] --> %s:%s",
            nowTime, __FUNCTION__, __LINE__, TYPEERR, printStr);
        break;
    default:
        break;
    }
    freePtr(nowTime);
    return;
}
void HwLongLog(HW_CHAR* printStr, HW_UINT logLevel)
{
    HWPP_INTO_FUNC;
    HW_CHAR nowTime[BUFSIZE_24BYTE] = {0};
    GetLocalTimeDevColonYMDHMS(nowTime, sizeof(nowTime));
    ASSERT_NULL_PTR2_RETVOID(nowTime, printStr);
    switch (logLevel)
    {
    case INFO:
        HwRecodeLongLog("%s [fun: %s line: %d --> %s:%s",
            nowTime, __FUNCTION__, __LINE__, TYPEINFO, printStr);
        break;
    case WARN:
        HwRecodeLongLog("%s [fun: %s line: %d --> %s:%s",
            nowTime, __FUNCTION__, __LINE__, TYPEWARN, printStr);
        break;
    case DEBUG:
        HwRecodeLongLog("%s [fun: %s line: %d --> %s:%s",
            nowTime, __FUNCTION__, __LINE__, TYPEDEBUG, printStr);
        break;
    case ERR:
        HwRecodeLongLog("%s [fun: %s line: %d --> %s:%s",
            nowTime, __FUNCTION__, __LINE__, TYPEERR, printStr);
        break;
    default:
        break;
    }
    return;
}
 */
