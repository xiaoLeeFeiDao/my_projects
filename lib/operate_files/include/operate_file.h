#ifndef __OPERATE_FILE_H_
#define __OPERATE_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include "pub_define.h"

#define ONLY_READ "r"
#define ONLY_WRITE "w"
#define READ_ADD "r+"
#define WRITE_ADD "w+"

#define HWPP_IO_FGETS_RETERR(buf, bufSize, stream) do{\
    HW_CHAR* tmpbuf = NULL;\
    HW_UINT realLength = 0;\
    tmpbuf = fgets(buf, bufSize, stream);\
    ASSERT_NULL_PTR2_RETERR(tmpbuf, buf);\
    realLength = strlen(buf) - 1;\
    if('\n' == buf[realLength]) {\
        buf[realLength] = '\0';\
    }\
}while(0)

#define HWPP_IO_FGETS_RETVOID(buf, bufSize, stream) do{\
    HW_CHAR* tmpbuf = NULL;\
    HW_UINT realLength = 0;\
    tmpbuf = fgets(buf, bufSize, stream);\
    ASSERT_NULL_PTR2_RETVOID(tmpbuf, buf);\
    realLength = strlen(buf) - 1;\
    if('\n' == buf[realLength]) {\
        buf[realLength] = '\0';\
    }\
}while(0)

#define FOPEN_ERR_BREAK(fp, fileName, openMode) do {\
    fp = fopen(fileName, openMode);\
    if(NULL == fp) {\
        HWPP_LOG_ERR("%s null. %s fopen failed by %s",#fp, fileName, openMode);\
        break;\
    }\
} while(0)

#define FOPEN_ERR_RETERR(fp, fileName, openMode) do {\
    fp = fopen(fileName, openMode);\
    if(NULL == fp) {\
        HWPP_LOG_ERR("%s null. %s fopen failed by %s",#fp, fileName, openMode);\
        return GENERAL_ERR;\
    }\
} while(0)

#define FCLOSE_ERR_BREAK(fp)  do{\
    if(NULL == fp) { \
        break;\
    }\
    fclose(fp); \
}while(0)
HW_INT ScanfLegalCheckBasicType(HW_VOID *data, HW_INT dataFormat);
HW_CHAR *FgetsEndWithZero(HW_CHAR *buf, HW_UINT bufSize, FILE *stream);

#endif
