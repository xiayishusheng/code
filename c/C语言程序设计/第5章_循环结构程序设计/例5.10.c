/*
 * =====================================================================================
 *
 *       Filename:  例5.10.c
 *
 *    Description:  Fibonacci数列
 *
 *        Version:  1.0
 *        Created:  2015年02月20日 20时02分01秒
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
    long f1, f2;
    int i;
    f1 = f2 = 1;
    for(i = 1; i <= 30; i++)
    {
        printf("%14ld\t%14ld\t",f1, f2);
        if(0 == i%2) printf("\n");//控制输出，每行四个
        f1 = f1 + f2;//前两项加起来是后一项
        f2 = f1 + f2;
    }
}
