/*
 * =====================================================================================
 *
 *       Filename:  例1.2.c
 *
 *    Description:  求两个整数中的较大者
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
    int x, y, z;      //定义整型变量x,y,z
    int max(int a, int b);       //声明函数max
    printf("请输入两个整数:\n"); //输出提示信息,增加程序的交互性
    scanf("%d%d", &x, &y);       //输入两个整数,并赋值给x,y
    z = max(x, y);               //调用max函数计算较大者
    printf("较大的数是:%d\n", z);//输出结果
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
