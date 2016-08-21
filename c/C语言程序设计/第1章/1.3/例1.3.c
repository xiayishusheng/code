/*
 * =====================================================================================
 *
 *       Filename:  例1.3.c
 *
 *    Description:  求1 - 1/2 + 1/3 - 1/4 + ... + 1/99 - 1/100的值
 *
 *        Version:  1.0
 *        Created:  2015年02月17日 21时48分49秒
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
    int sign = 1;
    float deno = 2.0, sum = 1.0, term;
    while(deno <= 100)
    {
        sign = -sign;
        term = sign / deno;
        sum = sum + term;
        deno = deno + 1;
    }
    printf("1 - 1/2 + 1/3 - 1/4 + ... + 1/99 - 1/100 = %f\n" , sum);
}
