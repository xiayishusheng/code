/*
 * =====================================================================================
 *
 *       Filename:  例5.8.c
 *
 *    Description:  sum = 2^0 + 2^1 + 2^2 + ... + 2^63
 *
 *        Version:  1.0
 *        Created:  2015年02月20日 19时40分49秒
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
    float sum, t;
    int i;
    for(t = 1.0, sum = 1.0, i = 1; i <= 63; i++)
    {
        t = t * 2;
        sum = sum + t;
    }
    printf("2^0 + 2^1 + 2^2 + ... + 2^63 = %e\n", sum);
}
