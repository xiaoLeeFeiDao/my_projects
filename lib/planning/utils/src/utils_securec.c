#include "securec.h"
size_t HwOsStrlen(HW_CHAR* sourceStr)
{
    if(NULL == sourceStr) {
        return 0;
    }
    return strlen(sourceStr);
}

HW_INT HwOsStrDup(HW_CHAR** destStr, const HW_CHAR* srcStr)
{
    HW_INT destStrLen = 0;
    HW_CHAR* tmpStr = NULL;
    do{
        if(NULL == srcStr) {
            break;
        }
        *destStr = strdup(srcStr);
        if(NULL == destStr) {
            break;
        }
        tmpStr = *destStr;
         while('\0' != *tmpStr) {
            destStrLen++;
            tmpStr++;
        }
        if(1024 > destStrLen) {
            return destStrLen;
        }
    } while (0);

    return GENERAL_ERR;
}

HW_CHAR* HwOsMallocByteInit(HW_UINT spaceSize, const char ch)
{
    HW_CHAR* retPtr = (HW_CHAR*)malloc(spaceSize);
    ASSERT_NULL_PTR_RETNULL(retPtr);
    memset(retPtr, ch, sizeof(retPtr));
    return retPtr;
}
