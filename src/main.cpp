/*** 
 * @Author: stone
 * @Date: 2020-04-11 23:49:18
 * @LastEditTime: 2020-05-23 15:39:19
 * @LastEditors: stone
 * @Description: 
 * @FilePath: /my_projects/src/main.cpp
 * @Copyright © 2000-2020 lldao9527@139.com All Rights Reserved.
 */
#include "securec.h"
#include "test.h"
#include <errno.h>
#include <iostream>
#include <limits.h>
// #include "find_string_todo.h"

using namespace std;
int main(int, char **)
{
#ifdef CPP_LEARN
    test();
#endif
#ifdef STR_PROCESS
    testStrtol();
#endif

    return 0;
}
