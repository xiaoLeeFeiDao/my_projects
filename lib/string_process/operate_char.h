/*************************************************************
*
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*
*   文件名称：operate_char.h
*   创 建 者：stone
*   创建日期：2019年08月04日
*   描    述：
*
*************************************************************/

#ifndef _OPERATE_CHAR_H_
#define _OPERATE_CHAR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operate_char.h"
#include "pub_define.h"
#include "securec.h"
int DeleteOneCharByAppearCounts(char* obj_str, const char del_char, HW_UINT count);
int DeleteCharFromWholeStr(char obj_str[], const char del_char);
HW_INT ReverseStr(HW_CHAR* obj_str);
HW_INT StrCpy(HW_CHAR* destStr, const HW_CHAR* srcStr);
HW_INT StrStr(HW_CHAR* objStr, const HW_CHAR* subObjStr);
#endif
