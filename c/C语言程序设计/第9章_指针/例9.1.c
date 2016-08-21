/*
 * =====================================================================================
 *
 *       Filename:  例9.1.c
 *
 *    Description:  指针变量的引用
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 19时50分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

void main()
{
    int a,b,c;
    int *p;
    a=5;
    b=a+3;
    p=&a;
    c=*p+3;
    printf("%d,%d\n",a,b);
    printf("%d,%d\n",*p,c);
}
