/*
 * =====================================================================================
 *
 *       Filename:  例6.12.c
 *
 *    Description:  strlen求字符串长度
 *
 *        Version:  1.0
 *        Created:  2015年02月21日 22时40分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

void main()
{
    int len;
    char str[] = "C language";
    len = strlen(str);
    printf("strlen(str)=%d\n", len);//不计算'\0'
    printf("sizeof(str)=%ld\n", sizeof(str));//计算'\0'
}
