#include "operate_char.h"
HW_INT DeleteOneCharByAppearCounts(HW_CHAR* obj_str, const HW_CHAR del_char, HW_UINT count)
{
    HW_INT ret = GENERAL_ERR;
    ASSERT_NULL_PTR_RETERR(obj_str);
   HW_UINT i = 0, j = 0, num = 0;
    for (i = 0; obj_str[i] != '\0'; i++) {

        if (obj_str[i] == del_char) {
            num++;
        }
        if(num != count) {
            obj_str[j] = obj_str[i];
            j++;
        }
    }
    obj_str[j] = '\0';
    return 0;
}

HW_INT DeleteCharFromWholeStr(HW_CHAR obj_str[], const HW_CHAR del_char)
{
    HW_INT ret = 0;
    HW_UINT i = 0, j = 0;
    ASSERT_NULL_PTR_RETERR(obj_str);
    for (i = 0; obj_str[i] != '\0'; i++){
        if (obj_str[i] != del_char){
            obj_str[j] = obj_str[i];
            j = j + 1;
        }
    }
    obj_str[j] = '\0';
    return 0;
}

HW_INT ReverseStr(HW_CHAR* obj_str)
{
    HW_INT ret = SUCC;
    size_t length = 0;
    HW_CHAR swapCh = 0;
    HW_UINT startIndex = 0, endIndex = 0;
    ASSERT_NULL_PTR_RETERR(obj_str);
    length = HwOsStrlen(obj_str);
    endIndex = length - 1;
    while(startIndex < endIndex) {
        swapCh = obj_str[startIndex];
        obj_str[startIndex] = obj_str[endIndex];
        obj_str[endIndex] = swapCh;
        startIndex++;
        endIndex--;
    }
    return ret;
}

HW_INT StrCpy(HW_CHAR* destStr, const HW_CHAR* srcStr)
{
    HW_INT ret = SUCC;
    ASSERT_NULL_PTR2_RETERR(destStr, srcStr);
#if PREFS == METHOD1
    while(*destStr++ = *srcStr++) {}
#elif PREFS == METHOD2
    HW_UINT i = 0;
    size_t length = HwOsStrlen(srcStr);
    for(i = 0; i < length; i++) {
        destStr[i] = srcStr[i];
    }
    destStr[length] = '\0';
#else
    while(*srcStr != '\0') {
        *destStr = *srcStr;
        destStr++;
        srcStr++;
    }
    *destStr = '\0';
#endif
    return ret;
}

HW_INT StrStr(HW_CHAR* objStr, const HW_CHAR* subObjStr)
{
    ASSERT_NULL_PTR2_RETERR(objStr, subObjStr);
    HW_INT ret = GENERAL_ERR;
    HW_INT OffsetNum = 0;
    HW_CHAR* tmpObjStr = NULL, *tmpSubObjStr = NULL;
    while(*objStr != '\0') {
        if(*objStr != *subObjStr) {
            OffsetNum++;
            objStr++;
            continue;
        }
        tmpObjStr = objStr;
        tmpSubObjStr = (HW_CHAR*)subObjStr;
        while(*tmpSubObjStr != '\0') {
            if(*tmpSubObjStr != *tmpObjStr) {
                OffsetNum++;
                objStr++;
                break;
            }
            tmpObjStr++;
            tmpSubObjStr++;
        }
        if(*tmpSubObjStr == '\0') {
            ret = OffsetNum;
            return ret;
        }
    }
    return ret;
}
