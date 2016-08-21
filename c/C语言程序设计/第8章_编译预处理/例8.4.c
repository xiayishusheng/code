/*
 * =====================================================================================
 *
 *       Filename:  例8.4.c
 *
 *    Description:  使用带参宏定义求两数中的较大着
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 15时04分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define MAX(a,b) (a>b)?a:b

int main()
{
    int x,y,max;
    printf("input two numbers(x,y):");
    scanf("%d %d", &x, &y);
    max = MAX(x, y);
    printf("max=%d\n", max);
}
