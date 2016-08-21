/*
 * =====================================================================================
 *
 *       Filename:  read_write_dat.c
 *
 *    Description:  已知IN.DAT中存有200个4位数，并已调用读函数readDat()把这些数存入数组a中，请编制一
 *              函数jsVal()，其功能是：依此从数组a中取出一个数，如果该4位数连续大于该4位数以后的5个数
 *              且该数是奇数，则统计出满足此条件的个数cnt，并把这些4位数按从小到大的顺序存入数组b中，
 *              最后调用写函数writeDat()把结果cnt及数组b中符合条件的4位数输出到OUT.DAT文件中。
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 13时32分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define MAX 200

int cnt=0;
int a[MAX], b[MAX];

void readDat();
void writeDat();
void jsVal();

void main()
{
    int i;
    readDat();
    jsVal();
    printf("满足条件的数=%d\n", cnt);
    for(i=0;i<cnt;i++)
    {
        printf("%d\t", b[i]);
    }
    printf("\n");
    writeDat();
}

void readDat()
{
    int i;
    FILE *fp;
    fp = fopen("IN.DAT", "r");
    for(i=0;i<MAX;i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
}

void writeDat()
{
    FILE *fp;
    int i;
    fp=fopen("OUT.DAT", "w");
    fprintf(fp, "满足条件的个数：%d\n", cnt);
    for(i=0;i<cnt;i++)
    {
        fprintf(fp, "%d\n", b[i]);
        close(fp);
    }
}

void jsVal()
{
    int t;
    int i,j=0;

    for(i=0;i<=MAX-5;i++)
    {
        if( (a[i] > a[i+1]) && (a[i] > a[i+2])
                && (a[i] > a[i+3]) && (a[i] > a[i+4])
                && (a[i] > a[i+5]) && (a[i]%2 != 0) )
        {
            b[j++] = a[i];
            cnt++;
        }
    }

    for(j=0;j<cnt-1;j++)
    {
        if(b[i]>b[i+1])
        {
            t      = b[i];
            b[i]   = b[i+1];
            b[i+1] = t;
        }
    }
}
