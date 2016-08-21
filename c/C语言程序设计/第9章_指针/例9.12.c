/*
 * =====================================================================================
 *
 *       Filename:  例9.12.c
 *
 *    Description:  将输入的两个整数按大小顺序输出，要求用函数交换两个实参，并在主调函数中输出实参
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 20时37分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

main()
{
    int a, b;
    int *ps1, *ps2;
    scanf("%d,%d", &a, &b);
    ps1=&a;
    ps2=&b;
    if(a<b)
    {
        swap(ps1, ps2);
    }
    printf("%d,%d\n", a, b);
}

