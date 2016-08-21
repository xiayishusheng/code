/*
 * =====================================================================================
 *
 *       Filename:  gen_random.c
 *
 *    Description:   
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
#include <stdlib.h>
#include <time.h>

#define MAX 200

int array[MAX];
void writeDat();

void main()
{
    int i, val;
    srand((unsigned)time(NULL));
    for(i=0;i<MAX;i++)
    {
        val = rand()%10000+1;
        printf("%d\n", val);
        array[i] = val;
    }
    writeDat();
}

void writeDat()
{
    FILE *fp;
    int i;
    fp=fopen("IN.DAT", "w");
    for(i=0;i<MAX;i++)
    {
        fprintf(fp, "%d\n", array[i]);
        close(fp);
    }
}
