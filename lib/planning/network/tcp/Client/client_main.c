#include "client_main.h"

HW_VOID ClientMain(HW_INT argc, HW_CHAR const *argv[])
{
    HW_INT ret = CreateClient(argc, argv);
    ASSERT_MINUS_RETVOID(ret);
    return;
}
