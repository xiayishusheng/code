/*
 * =====================================================================================
 *
 *       Filename:  例2.1.c
 *
 *    Description:  符号常量的使用
 *
 *        Version:  1.0
 *        Created:  2015年02月17日 22时36分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define PI 3.141592653589
#define R 5.3

void main()
{
    printf("圆面积 = %f\n", PI * R * R);
    printf("圆周长 = %f\n", 2 * PI * R);
}
