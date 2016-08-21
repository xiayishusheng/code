/*
 * =====================================================================================
 *
 *       Filename:  例9.4.c
 *
 *    Description:  输出数组中的全部元素
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 20时16分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

main()
{
    int *p,i,a[5];
    p=a;
    for(i=0;i<5;i++)
    {
        scanf("%d", p++);   //不能写成&p++,因为p本身就是地址
    }
    p=a;
    for(i=0;i<5;i++,p++)
    {
        printf("a[%d]=%d\n",i,*p);
    }
}
