/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  利用LD_PRELOAD hook代码
 *
 *        Version:  1.0
 *        Created:  2019年06月13日 14时26分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if( strcmp(argv[1], "test") )
    {
        printf("Incorrect password\n");
    }
    else
    {
        printf("Correct password\n");
    }
    return 0;
}
