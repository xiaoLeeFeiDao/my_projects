#include "hwpp_util_time.h"

HW_VOID
GetLocalTimeDevColonYMDHMS(HW_CHAR* timeBuf, HW_UINT bufSize)
{
    ASSERT_NULL_PTR_RETVOID(timeBuf);
    time_t t = time(NULL);
    struct tm* lt = localtime(&t);
    strftime(timeBuf, bufSize - 1, "%Y-%m-%d %H:%M:%S", lt);

    return;
}
