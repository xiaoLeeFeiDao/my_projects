/*** 
 * @Author: stone
 * @Date: 2020-04-11 23:16:02
 * @LastEditTime: 2020-05-01 22:03:00
 * @LastEditors: stone
 * @Description: 
 * @FilePath: /server_frame/src/string_process_center/find_string_todo.h
 * @Copyright © 2000-2020 lldao9527@139.com All Rights Reserved.
 */
#ifndef _FIND_STRING_TODO_H
#define _FIND_STRING_TODO_H

#include "find_string_todo.h"
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif
#define BUF_SIZE_32 32
#define BUF_SIZE_64 64
#define BUF_SIZE_128 128
#define BUF_SIZE_512 512
#define BUF_SIZE_1024 1024
enum { INPUT_SIZE = 30 };
int findStrDel(const char* src, char* subStr, int seqAppears);
int delete_sub_str(const char* str, const char* sub_str, char* result_str);
void testStr();
int testStrtol();

#ifdef __cplusplus
}
#endif
#endif // _FIND_STRING_TODO_H