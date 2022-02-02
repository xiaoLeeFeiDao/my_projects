/*** 
 * @Author: stone
 * @Date: 2020-05-04 18:19:39
 * @LastEditTime: 2020-05-23 15:47:51
 * @LastEditors: stone
 * @Description: 
 * @FilePath: /my_projects/src/string_process_center/find_string_todo.cpp
 * @Copyright © 2000-2020 lldao9527@139.com All Rights Reserved.
 */

#include "find_string_todo.h"

using namespace std;
int findStrDel(const char* src, char* subStr, int seqAppears)
{
    return 0;
}
int delete_sub_str(const char* str, const char* sub_str, char* result_str)
{
    int count = 0;
    int str_len = strlen(str);
    int sub_str_len = strlen(sub_str);

    if (str == NULL) {
        result_str = NULL;
        return 0;
    }

    if (str_len < sub_str_len || sub_str == NULL) {
        while (*str != '\0') {
            *result_str = *str;
            str++;
            result_str++;
        }

        return 0;
    }

    while (*str != '\0') {
        while (*str != *sub_str && *str != '\0') {
            *result_str = *str;
            str++;
            result_str++;
        }

        if (strncmp(str, sub_str, sub_str_len) != 0) {
            *result_str = *str;
            str++;
            result_str++;
            continue;
        } else {
            count++;
            str += sub_str_len;
        }
    }

    *result_str = '\0';

    return count;
}

void testStr()
{
    int cnt = 0;
    char optStr[BUF_SIZE_32] = { 0 };
    char buf[BUF_SIZE_128] = { 0 };
    char resBuf[BUF_SIZE_128] = { 0 };
    printf("hello, [%s:%d]\n", __FUNCTION__, __LINE__);
    //FILE* fp = fopen("test_file.txt", "r");
    cin >> buf;
    cin >> optStr;
    cnt = delete_sub_str(buf, optStr, resBuf);
    printf("%s %d\n", resBuf, cnt);
    return;
}

int testStrtol()
{
    char* ptr;
    long ret;
    char str[INPUT_SIZE];

    char* resGet = fgets(str, INPUT_SIZE, stdin);
    printf("resGet:%s\n", resGet);

    ret = strtol(str, &ptr, 10);

    if (ret == LONG_MAX || ret == LONG_MIN) {
        perror("!! Problem is -> ");
    } else if (ret) {
        printf("The number is %ld\n", ret)
    } else {
        printf("No number found input is -> %s\n", ptr);
    }

    return 0;
}