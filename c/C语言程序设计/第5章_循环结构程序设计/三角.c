/*
 * =====================================================================================
 *
 *       Filename:  三角※.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年02月20日 20时36分52秒
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
    int i, j, k, num, line;
    printf("输入行数:");
    scanf("%d", &line);
    for(num = 1; num <= line; num++)
    {
#if 1
        for(i = 1; i <= line-num; i++)
        {
            printf(" ");
        }

        for(j = 1; j <= 2*num -1; j++)
        {
            printf("*");
        }

        for(k = 1; k <= line-num; k++)
        {
            printf(" ");
        }
#endif

#if 0
        for(int x = 1; x <= 2*line - 1; x++)
        {
            printf("*");
        }
#endif
        printf("\t\t--->line:%02d\n", num);
    }
}
