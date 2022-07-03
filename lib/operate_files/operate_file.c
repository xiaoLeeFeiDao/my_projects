#include "operate_file.h"

HW_CHAR* FgetsEndWithZero(HW_CHAR* buf, HW_UINT bufSize, FILE* stream)
{
    ASSERT_NULL_PTR2_RETNULL(buf, stream);
    HW_CHAR* tmpbuf = NULL;
    HW_UINT realLength = 0;
    tmpbuf = fgets(buf, bufSize, stream);
    ASSERT_NULL_PTR2_RETNULL(tmpbuf, buf);
    realLength = strlen(buf) - 1;
    if('\n' == buf[realLength]) {
         buf[realLength] = '\0';
         return buf;
    }
    return buf;
}

HW_INT ScanfLegalCheckBasicType(HW_VOID *data, HW_INT dataFormat)
{
    HW_INT ret = SUCC;
    HW_CHAR *strType = NULL;
    HW_UINT* uintType = NULL;
    HW_INT* intType = NULL;
    HW_CHAR* charType = NULL;
    switch (dataFormat)
    {
    case STR:
        strType = (HW_CHAR *)data;
        ret = scanf("%s", strType);
        if (1 != ret)
        {
            HWPP_LOG_ERR("scanf get legal data");
            getchar();
            return GENERAL_ERR;
        }
        else
        {
            data = strType;
            break;
        }
    case UINT:
        uintType = (HW_UINT *)data;
        ret = scanf("%u", uintType);
        if (1 != ret)
        {
            HWPP_LOG_ERR("scanf get legal data");
            getchar();
            return GENERAL_ERR;
        }
        else
        {
            data = uintType;
            break;
        }
    case INT:
        intType = (HW_INT *)data;
        ret = scanf("%d", intType);
        if (1 != ret)
        {
            HWPP_LOG_ERR("scanf get legal data");
            getchar();
            return GENERAL_ERR;
        }
        else
        {
            data = intType;
            break;
        }
    case CH:
        charType = (HW_CHAR *)data;
        ret = scanf("%c", charType);
        if (1 != ret)
        {
            HWPP_LOG_ERR("scanf get legal data");
            getchar();
            return GENERAL_ERR;
        }
        else
        {
            data = charType;
            break;
        }
    default:
        break;
    }
    getchar();
    return SUCC;
}
