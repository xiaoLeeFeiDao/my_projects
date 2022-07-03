#include "check_mac.h"

/*
*brief
*param: pattern,正则表达式字符串;value,the mac address.
*return value: if susscess,0 is returned,or 1 is returned on error.
*/
HW_INT ereg(HW_CHAR *pattern, HW_CHAR *value)
{
    HW_INT r, cflags = 0;
    regmatch_t pm[10];
    const size_t nmatch = 10;
    regex_t reg;

    r = regcomp(&reg, pattern, cflags);
    if (r == 0)
    {
        r = regexec(&reg, value, nmatch, pm, cflags);
    }
    regfree(&reg);

    return r;
}
/*
*brief check whether the mac address is format-right
*param: the mac address
*return value: if susscess,0 is returned,or 1 is returned on error.
*/
HW_INT isValidMac(HW_CHAR* macAddr)
{
    HW_INT r = SUCC;
    HW_CHAR reg[1024] = {"^[a-f0-9A-F]\\([a-f0-9A-F][\\:,\\-][a-f0-9A-F]\\)\\{5\\}[a-f0-9A-F]$"};
    r = ereg(reg, macAddr);
    if(SUCC != r)
        return GENERAL_ERR;
    return r;
}

HW_INT CheckMacWithHyphen(const HW_CHAR* mac)
{
    HWPP_INTO_FUNC;
	HW_INT ret = SUCC;
	const HW_CHAR* pattern = "^([A-Fa-f0-9]{2}[-,:]){5}[A-Fa-f0-9]{2}$";
	const HW_INT cflags = REG_EXTENDED | REG_NEWLINE;
	HW_CHAR ebuf[BUFSIZE_128BYTE] = {0};
	regmatch_t pmatch[1] = {0};
	HW_INT nmatch = 10;
	regex_t reg;
    memset(&reg, 0, sizeof(regex_t));
    do {
        ret = regcomp(&reg, pattern, cflags);//编译正则模式
        if(SUCC != ret) {
            regerror(ret, &reg, ebuf, sizeof(ebuf));
            HWPP_LOG_ERR("regcomp fail: %s, ret:%d pattern '%s' \n",ebuf, ret, pattern);
            break;
        }

        ret = regexec(&reg, mac, nmatch, pmatch,0);//执行正则表达式和缓存的比较,
        if(SUCC != ret) {
            regerror(ret, &reg, ebuf, sizeof(ebuf));
            HWPP_LOG_ERR("regexec fail: %s, ret:%d mac:\"%s\" ", ebuf, ret, mac);
            break;
        }
        HWPP_LOG_INFO("match success");
        regfree(&reg);
        HWPP_OUT_FUNC;
        return SUCC;
    } while(0);

	regfree(&reg);
	return GENERAL_ERR;
}

HW_INT CheckMacNoHyphen(const HW_CHAR* mac)
{
    HWPP_INTO_FUNC;
    ASSERT_NULL_PTR_RETERR(mac);
    const HW_CHAR* offSetMac = mac;
    while ('\0' != *offSetMac) {
        if (('0' <= *offSetMac && '9' >= *offSetMac) ||
            ('A' <= *offSetMac && 'F' >= *offSetMac) || ('a' <= *offSetMac && 'f' >= *offSetMac)) {
            offSetMac++;
            continue;
        } else {
            return GENERAL_ERR;
        }
    }
    HWPP_OUT_FUNC;
	return SUCC;
}
HW_INT CheckMac(const HW_CHAR* mac)
{
    HWPP_INTO_FUNC;
    ASSERT_NULL_PTR_RETERR(mac);
    HW_INT ret = SUCC;
    size_t macLen = strlen(mac);
    if (12 == macLen) {
        ret = CheckMacNoHyphen(mac);
        ASSERT_MINUS_RETSELF(ret);
    } else if (17 == macLen)
    {
        ret = CheckMacWithHyphen(mac);
        ASSERT_MINUS_RETSELF(ret);
    } else {
        return GENERAL_ERR;
    }
    HWPP_LOG_INFO("match succes.MAC is available.ret:%d,mac:%s", ret, mac);
    HWPP_OUT_FUNC;
}
