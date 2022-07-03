/*************************************************************
*
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*
*   文件名称：hwpp_util_log.h
*   创 建 者：stone
*   创建日期：2019年08月15日
*   描    述：
*
*************************************************************/

#ifndef _HWPP_UTIL_LOG_H_
#define _HWPP_UTIL_LOG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <errno.h>
#include "hwpp_util_log.h"
#include "pub_define.h"
#include "hwpp_util_time.h"
#include "securec.h"

// void HwRecodeLongLog(HW_CHAR *format, ...);
// void HwRecodeLogLengthHalfKB(HW_CHAR *format, ...);
// void HwLog(HW_CHAR* printStr, HW_UINT logLevel);
// void HwLongLog(HW_CHAR* printStr, HW_UINT logLevel);

#define HWPP_INTO_FUNC do {\
    HW_CHAR nowTime[BUFSIZE_24BYTE] = {0};\
    GetLocalTimeDevColonYMDHMS(nowTime, sizeof(nowTime));\
    ASSERT_NULL_PTR_BREAK(nowTime);\
    printf("%s Into func:%s ---------------->\n", nowTime, __FUNCTION__);\
}while (0)

#define HWPP_OUT_FUNC do {\
    HW_CHAR nowTime[BUFSIZE_24BYTE] = {0};\
    GetLocalTimeDevColonYMDHMS(nowTime, sizeof(nowTime));\
    ASSERT_NULL_PTR_BREAK(nowTime);\
    printf("%s out func:%s <-----------------\n", nowTime, __FUNCTION__);\
}while (0)

#define HWPP_FPRINTF() do {\
    HW_CHAR nowTime[BUFSIZE_24BYTE] = {0};\
    GetLocalTimeDevColonYMDHMS(nowTime, sizeof(nowTime));\
    ASSERT_NULL_PTR_BREAK(nowTime);\
    fprintf(stderr, "%s [file:%s func:%s line:%d] %s-->Socket error:%s\n\a",\
    nowTime, __FILE__, __FUNCTION__, __LINE__, TYPEWARN, strerror(errno));\
}while (0)

#endif
