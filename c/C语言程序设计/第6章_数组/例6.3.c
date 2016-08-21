/*
 * =====================================================================================
 *
 *       Filename:  例6.3.c
 *
 *    Description:  冒泡排序
 *
 *        Version:  1.0
 *        Created:  2015年02月20日 21时31分03秒
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
    int index;// 索引
    int times;// 次数
    int temp; // 临时交换变量
    int array[10] = {12, 14, 23, 34, 45, 67, 55, 89, 80, 99};

/*
    int array[10];
    printf("\nInput 10 numbers:\n");
    for(i=0; i<10; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("\n");
*/

    for(times=1; times<10; times++)
    {
        for(index=0; index<10-times; index++)
        {
            if(array[index] > array[index+1])
            {
                temp           = array[index];
                array[index]   = array[index+1];
                array[index+1] = temp;
            }
        }
    }

    for(index=0; index<10; index++)
    {
        printf("%-4d", array[index]);
    }
    printf("\n");
}
