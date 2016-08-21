/*
 * =====================================================================================
 *
 *       Filename:  例7.4.c
 *
 *    Description:  递归调用
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 10时07分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int age(int n);

main()
{
    printf("%d\n", age(5));
}

int age(int n)
{
    int c;
    if(n==1)
    {
        c = 10;
    }
    else
    {
        c = age(n-1) + 2;
    }
    return c;
}
