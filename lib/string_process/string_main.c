#include "string_main.h"
void test_operate_char()
{
    HW_INT ret = SUCC;
    HW_CHAR buf[BUFSIZE_ONE_KB] = {0};
    HW_CHAR* tmpBuf = NULL;
    HW_CHAR target = '\0';
    printf("input the string u want to deal and the HW_CHAR u want to delete\n");
    ret = ScanfLegalCheckBasicType(buf, 0);
    ASSERT_FAILED_RETVOID(ret);
#if OPERATE_SWITCH == SWITCH1 || OPERATE_SWITCH == SWITCH2 || OPERATE_SWITCH == SWITCH3
    ret = ScanfLegalCheckBasicType(&target, 3);
    ASSERT_FAILED_RETVOID(ret);
#endif
#if OPERATE_SWITCH == SWITCH1
    DeleteCharFromWholeStr(buf, target);
#elif OPERATE_SWITCH == SWITCH2
    printf("Enter number of times you want to delete.\n");
    HW_UINT count = 0;
    ret = ScanfLegalCheckBasicType(&count, 1);
    ASSERT_FAILED_RETVOID(ret);
    // HW_UINT count = (HW_UINT)fgetc(stdin);
    // HW_INT count = 0;
    // scanf("%d",&count);
    DeleteOneCharByAppearCounts(buf, target, (HW_UINT)count);
#elif OPERATE_SWITCH == SWITCH3
#elif OPERATE_SWITCH == SWITCH4
    HW_INT ret = ReverseStr(buf);
    ASSERT_MINUS_RETVOID(ret);
#elif OPERATE_SWITCH == SWITCH5
    HW_CHAR destStr[BUFSIZE_128BYTE] = {0};
    HW_INT ret = StrCpy(destStr, buf);
    ASSERT_MINUS_RETVOID(ret);
    HWPP_LOG_INFO("destStr:%s", destStr);
#endif
    HWPP_LOG_INFO("buf:%s", buf);
    return;
}
