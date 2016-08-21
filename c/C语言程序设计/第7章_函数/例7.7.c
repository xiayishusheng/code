/*
 * =====================================================================================
 *
 *       Filename:  例7.7.c
 *
 *    Description:  利用选择排序法对数组元素由大到小进行排序
 *    算法分析：
 *        (1) 从n个数中选择最大的一个，把他和第一个数组元素交换
 *        (2) 从剩下的n-1个数中选择最大的一个，把他和第二个数组元素交换
 *        (3) 依此类推，知道从最后两个元素中选出倒数第二大的元素并把他和倒数第二个元素交换为止
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 11时29分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
void nzp(int a[])
{
    int i,j,k,t;
    for(int i=0;i<4;i++)
    {
        k=i;
        for(j=i+1;j<5;j++)
        {
            if(a[j]>a[k])
            {
                k=j;
            }
        }
        t=a[k];
        a[k]=a[i];
        a[i]=t;
    }
}

int main()
{
    int b[5], i;
    printf("\nPlese input 5 numbers:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d", &b[i]);
    }
    printf("Initial values of array b are:");
    for(i=0;i<5;i++)
    {
        printf("%-4d", b[i]);
    }

    nzp(b);

    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("%-4d", b[i]);
    }

    printf("\n");
}
