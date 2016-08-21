/*
 * =====================================================================================
 *
 *       Filename:  例1.1.c
 *
 *    Description:  求任意两个整数之和
 *
 *        Version:  1.0
 *        Created:  2015年02月17日 21时03分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>    //编译预处理

void main()           //主函数
{
    int a, b, sum;               //定义整型变量
    printf("请输入两个整数:\n"); //输出提示信息,增加程序的交互性
    scanf("%d%d", &a, &b);       //输入两个整数,并赋值给a,b
    sum = a + b;                        //计算sum
    printf("%d + %d = %d\n", a, b, sum);//输出结果
}
