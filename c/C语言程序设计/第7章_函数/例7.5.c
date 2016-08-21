/*
 * =====================================================================================
 *
 *       Filename:  例7.5.c
 *
 *    Description:  反向输出一个整数
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 10时15分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

void print_int(int x )
{
    if(x>=0 && x<=9)
    {
        printf("%d", x);
    }
    else
    {
        printf("%d", x%10); //输出x的个位数字
        print_int(x/10);    //将x中除个位外的其他数字作为一个新的整数，继续递归
    }
}

main()
{
    int n;
    printf("输入一个整数:");
    scanf("%d", &n);
    if(n<0)
    {
        n=-n;
        putchar('-');
    }
    print_int(n);
    printf("\n");
}
