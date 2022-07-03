#include "network_main.h"

void NetworkMain()
{
    HWPP_INTO_FUNC;
    HW_CHAR macStr[BUFSIZE_32BYTE] = {0};
    HW_INT ret = SUCC;
    while (1)
    {
        memset(macStr, 0, sizeof(macStr));
        HWPP_IO_FGETS_RETVOID(macStr, sizeof(macStr), stdin);
        ret = CheckMac(macStr);
        if (SUCC != ret) {
            HWPP_LOG_ERR("match failed.MAC is unavailable.ret:%d,mac:%s", ret, macStr);
        }
    }
    HWPP_OUT_FUNC;
    return;
}
