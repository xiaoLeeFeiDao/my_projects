#ifndef __CHECK_MAC_H_
#define __CHECK_MAC_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "pub_define.h"
#include "hwpp_util_log.h"
HW_INT ereg(HW_CHAR* pattern, HW_CHAR* value);
HW_INT isValidMac(HW_CHAR* macAddr);
HW_INT CheckMac(const HW_CHAR* mac);
HW_INT CheckMacWithHyphen(const HW_CHAR* mac);
HW_INT CheckMacNoHyphen(const HW_CHAR* mac);

#endif
