#include "server_main.h"

HW_VOID ServerMain()
{
    HW_INT ret = CreatServer();
    ASSERT_MINUS_RETVOID(ret);
    return;
}
