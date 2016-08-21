/*
 * =====================================================================================
 *
 *       Filename:  例7.1.c
 *
 *    Description:  定义power，其功能是求x的n次方
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 09时21分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

float power(float x, int n)
{
    int i;
    float t=1;
    for(i=1;i<=n;i++)
    {
        t=t*x;  //共乘n次
    }
    return t;   //返回结果
}
