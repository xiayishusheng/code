/*
 * =====================================================================================
 *
 *       Filename:  例5.9.c
 *
 *    Description:  |- 5i + 3j + k/3 = 100
 *                  |- i + j + k = 100
 *
 *        Version:  1.0
 *        Created:  2015年02月20日 19时49分35秒
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
    int i, j, k;
    int m = 100/5, n = 100/3;
    for(i = 1; i < m; i++)
    {
        for(j = 1; j < n; j++)
        {
            k = 100 - i - j;
            if(k%3 == 0 && 5*i + 3*j + k/3 == 100)
            {
                printf("i=%d,\tj=%d,\tk=%d\n", i, j, k);
            }
        }
    }
}

/* 输出结果
i=4,	j=18,	k=78
i=8,	j=11,	k=81
i=12,	j=4,	k=84
*/
