/*************************************************************
*
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*
*   文件名称：pub_define.h
*   创 建 者：stone
*   创建日期：2019年08月04日
*   描    述：
*
*************************************************************/

#ifndef __PUB_DEFINE_H_
#define __PUB_DEFINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdarg.h>
#include <time.h>
#include "pub_define.h"

#define MAIN_ARG_NUM1 1
#define MAIN_ARG_NUM2 2
#define MAIN_ARG_NUM3 3
#define MAIN_ARG_NUM4 4
typedef enum  {
    SUCC = 0,
    GENERAL_ERR = -1,
    ARG_ERR = -3
} retValue;

typedef enum {
    TURE = 1,
    FALSE = 0
} boolValue;

typedef  unsigned int  HW_UINT;
typedef   int  HW_INT;
typedef  char  HW_CHAR;
typedef  void  HW_VOID;

#define HW_MAX_INT (((unsigned)(-1))>>1)
#define HW_MIN_INT (~((unsigned)(-1))>>1)

#define STR   0
#define UINT 1
#define INT    2
#define CH     3

#define BUFSIZE_8BYTE 8
#define BUFSIZE_16BYTE 16
#define BUFSIZE_24BYTE 24
#define BUFSIZE_32BYTE 32
#define BUFSIZE_48BYTE 48
#define BUFSIZE_64BYTE 64
#define BUFSIZE_128BYTE 128
#define BUFSIZE_256BYTE 256
#define BUFSIZE_HALF_KB 512
#define BUFSIZE_ONE_KB 1024

#ifndef OPERATE_SWITCH
#define SWITCH1 1
#define SWITCH2 2
#define SWITCH3 3
#define SWITCH4 4
#define SWITCH5 5
#define OPERATE_SWITCH  SWITCH2
#endif

#ifndef PREFS
#define METHOD1 1
#define METHOD2 2
#define METHOD3 3
#define METHOD4 4
#define METHOD5 5
#define PREFS METHOD1
#endif

#ifndef LOG_STATUS
#define LOG_CLOSE 0
#define LOG_OPEN_LV1 1
#define LOG_OPEN_LV2 2
#define LOG_STATUS LOG_OPEN_LV2
#endif

#define LOGPATH "./log/running_log.txt"
#define INFO 0
#define WARN 1
#define DEBUG 2
#define ERR 3
#define TYPEINFO "info"
#define TYPEWARN "warning"
#define TYPEDEBUG "debug"
#define TYPEERR "error"

HW_VOID HwLog(HW_CHAR* positionInfo, const HW_CHAR* fmt, ...);
#define HWPP_LOG_INFO(fmt...) do{\
    HW_CHAR positionInfo[BUFSIZE_128BYTE] = {0};\
    HW_INT positionInfoLen = snprintf(positionInfo, sizeof(positionInfo),\
            "[file:%s func:%s line:%d] %s-->", __FILE__, __FUNCTION__, __LINE__, TYPEINFO);\
    if(NULL == positionInfo || positionInfoLen > sizeof(positionInfo)) {\
        break;\
    }\
    HwLog(positionInfo,##fmt);\
}while(0)

#define HWPP_LOG_WARN(fmt...) do{\
    HW_CHAR positionInfo[BUFSIZE_128BYTE] = {0};\
    HW_INT positionInfoLen = snprintf(positionInfo, sizeof(positionInfo),\
            "[file:%s func:%s line:%d] %s-->", __FILE__, __FUNCTION__, __LINE__, TYPEWARN);\
    if(NULL == positionInfo || positionInfoLen > sizeof(positionInfo)) {\
        break;\
    }\
    HwLog(positionInfo,##fmt);\
}while(0)

#define HWPP_LOG_DEBUG(fmt...) do{\
    HW_CHAR positionInfo[BUFSIZE_128BYTE] = {0};\
    HW_INT positionInfoLen = snprintf(positionInfo, sizeof(positionInfo),\
            "[file:%s func:%s line:%d] %s-->", __FILE__, __FUNCTION__, __LINE__, TYPEDEBUG);\
    if(NULL == positionInfo || positionInfoLen > sizeof(positionInfo)) {\
        break;\
    }\
    HwLog(positionInfo,##fmt);\
}while(0)

#define HWPP_LOG_ERR(fmt...) do{\
    HW_CHAR positionInfo[BUFSIZE_128BYTE] = {0};\
    HW_INT positionInfoLen = snprintf(positionInfo, sizeof(positionInfo),\
            "[file:%s func:%s line:%d] %s-->", __FILE__, __FUNCTION__, __LINE__, TYPEERR);\
    if(NULL == positionInfo || positionInfoLen > sizeof(positionInfo)) {\
        break;\
    }\
    HwLog(positionInfo,##fmt);\
}while(0)

#define ASSERT_NULL_PTR_RETERR(ptr)  do{\
    if(NULL == ptr) { \
        HWPP_LOG_ERR("%s is null, ret:%d", #ptr, GENERAL_ERR); \
        return GENERAL_ERR; \
    }\
}while(0)

#define ASSERT_NULL_PTR_RETNULL(ptr)  do{\
    if(NULL == ptr) { \
        HWPP_LOG_ERR("%s is null.", #ptr); \
        return ptr; \
    }\
}while(0)

#define ASSERT_NULL_PTR_RETVOID(ptr)  do{\
    if(NULL == ptr) { \
        HWPP_LOG_ERR("%s is null.", #ptr); \
        return; \
    }\
}while(0)

#define ASSERT_NULL_PTR_BREAK(ptr)  do{\
    if(NULL == ptr) { \
        HWPP_LOG_ERR("%s is null, ret:%d", #ptr, GENERAL_ERR); \
        break; \
    }\
}while(0)

#define ASSERT_NULL_PTR2_RETNULL(ptr1, ptr2)  do{\
    if(NULL == ptr1 || NULL == ptr2) { \
        HWPP_LOG_ERR("%s or %s is null", #ptr1, #ptr2); \
        return NULL; \
    }\
}while(0)

#define ASSERT_NULL_PTR2_RETVOID(ptr1, ptr2)  do{\
    if(NULL == ptr1 || NULL == ptr2) { \
        HWPP_LOG_ERR("%s or %s is null", #ptr1, #ptr2); \
        return; \
    }\
}while(0)

#define ASSERT_NULL_PTR2_RETERR(ptr1, ptr2)  do{\
    if(NULL == ptr1 || NULL == ptr2) { \
        HWPP_LOG_ERR("%s or %s is null, ret:%d", #ptr1, #ptr2, GENERAL_ERR); \
        return GENERAL_ERR; \
    }\
}while(0)

#define ASSERT_FAILED_RETVOID(ret)  do{\
    if(SUCC != ret) { \
        HWPP_LOG_ERR("%s is %d.", #ret, ret); \
        return; \
    }\
}while(0)

#define ASSERT_MINUS_RETVOID(ret)  do{\
    if(0 > ret) {\
        HWPP_LOG_ERR("%s is negative:%d", #ret, ret); \
        return; \
    }\
}while(0)

#define ASSERT_MINUS_RETSELF(ret)  do{\
    if(0 > ret) {\
        HWPP_LOG_ERR("%s:%d is negative, return:%d", #ret, ret, ret); \
        return ret; \
    }\
}while(0)

#define ASSERT_UINT_PRE_LESSTHAN_REAR_RETERR(pre, rear)  do{\
    if(pre < rear) { \
        HWPP_LOG_ERR("%s less than %s, ret:%d", #pre, #rear, GENERAL_ERR); \
        return GENERAL_ERR; \
    }\
}while(0)

#define ASSERT_NOT_EQUEL_RETERR(arg1, arg2) do {\
    if(arg1  != arg2) {\
        HWPP_LOG_ERR("%d != %d", arg1, arg2); \
        return GENERAL_ERR; \
    }\
}while(0)

#define freePtr(ptr)  do{\
    if(NULL != ptr) { \
        free(ptr); \
        ptr = NULL; \
    }\
}while(0)

#endif
