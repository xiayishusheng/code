/*
 * =====================================================================================
 *
 *       Filename:  例9.2.c
 *
 *    Description:  输入a和b两个整数，用指针实现按先大后小的顺序输出
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 19时58分34秒
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
    int *p1, *p2, *p, a, b;
    scanf("%d,%d", &a, &b);
    p1 = &a;    //使p1指向整型变量a
    p2 = &b;    //使p2指向整型变量b
    if(a<b)     //改变p1和p2的指向，使p1指向a、b中较大者，p2指向较小者
    {
        p=p1;
        p1=p2;
        p2=p;
    }
    printf("a=%d,b=%d\n", a, b);
    printf("max=%d,min=%d\n", *p1, *p2);
}
