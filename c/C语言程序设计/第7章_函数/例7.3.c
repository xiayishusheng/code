/*
 * =====================================================================================
 *
 *       Filename:  例7.3.c
 *
 *    Description:  计算 s = 2^2! + 3^2! + 4^2!
 *
 *        Version:  1.0
 *        Created:  2015年02月21日 23时03分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

long power(int p);//求幂
long jiecheng(int q);//求阶乘

long power(int p)
{
    return jiecheng(p*p);
}

long jiecheng(int q)
{
    int i;
    long ret = 1;
    for(i=1; i<=q; i++)
    {
        ret = ret*i;
    }
    return ret;
}

void main()
{
    int i;
    long sum=0;
    for(i=2; i<=4; i++)
    {
        sum = sum + power(i);
    }
    printf("2^2! + 3^2! + 4^2! = %ld\n", sum);
}
