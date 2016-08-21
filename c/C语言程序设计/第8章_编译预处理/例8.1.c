/*
 * =====================================================================================
 *
 *       Filename:  例8.1.c
 *
 *    Description:  使用无参宏定义计算s=3*(y*y+3*y) + 4*(y*y+3*y) + 5*(y*y+3*y)
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 14时58分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

#define M (y*y + 3*y)

int main()
{
    int s,y;
    printf("Plese input a number:");
    scanf("%d", &y);
    s=3*M + 4*M + 5*M;
    printf("s=%d\n", s);
}
