/*
 * =====================================================================================
 *
 *       Filename:  例7.2.c
 *
 *    Description:  函数的值传递方式
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 09时39分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void swap(int a, int b);

void main()
{
    int x=6,y=9;
    printf("x=%d, y=%d\n", x, y);
    swap(x, y);
    printf("x=%d, y=%d\n", x, y);
}

void swap(int a, int b)
{
    int i;
    printf("a=%d, b=%d\n", a, b);
    i=a;
    a=b;
    b=i;
    printf("a=%d, b=%d\n", a, b);
}
