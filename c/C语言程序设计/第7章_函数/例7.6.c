/*
 * =====================================================================================
 *
 *       Filename:  例7.6.c
 *
 *    Description:  从键盘上输入两个字符串，不用字符串函数strcmp()比较两者的大小
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 10时39分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compchar(char c1, char c2)
{
    int t;
    t = c1 - c2;
    return t;
}

void main()
{
    int i,flag;
    char str1[80], str2[80];
    i = 0;

    gets(str1);
    gets(str2);

    do
    {
        flag=compchar(str1[i], str2[i]);    //数组元素作为实参
        i++;
    }
    while( (str1[i] != '\0') && (str2[i] != '\0') && (0 == flag) );   //只要有一个字符串到了末尾，比较就结束

    if(0 == flag)
    {
        printf("%s = %s\n", str1, str2);
    }
    else if(flag > 0)
    {
        printf("%s > %s\n", str1, str2);
    }
    else if(flag < 0)
    {
        printf("%s < %s\n", str1, str2);
    }
}

