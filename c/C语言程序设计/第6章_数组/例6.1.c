#include <stdio.h>

void main()
{
    int s[10];
    int i;
    for(i=0; i<=9; i++)
    {
        s[i] = i*i;
    }

    for(i=0; i<=9; i++)
    {
        printf("%-4d", s[i]);
    }

    printf("\n");
}
