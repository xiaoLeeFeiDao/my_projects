#ifndef __SECUREC_H_
#define __SECUREC_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pub_define.h"
#include "securec.h"

size_t HwOsStrlen(HW_CHAR* sourceStr);
HW_CHAR* HwOsMallocByteInit(HW_UINT spaceSize, const char ch);
HW_INT HwOsStrDup(HW_CHAR** destStr, const HW_CHAR* srcStr);

#define STRDUP_ERR_BREAK(destStrLen, destStr, srcStr) do{\
    destStrLen = HwOsStrDup(destStr, srcStr);\
    if(0 > destStrLen) {\
        HWPP_LOG_ERR("%s:%d. strdup failed!", #destStrLen, destStrLen);\
        break;\
    }\
} while(0)
#endif
