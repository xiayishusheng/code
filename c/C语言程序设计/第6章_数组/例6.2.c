#include <stdio.h>

void main()
{
    int a[5];
    int b[]={1, 3, 5 ,7 ,9};
    int i;

    for(i=0; i<5; i++)
    {
        a[i] = 2*i + 1;
        printf("%-4d", a[i]);
    }
    printf("\n");

    for(i=0; i<5; i++)
    {
        a[i] = b[i]*b[i];
        printf("%-4d", a[i]);
    }
    printf("\n");
}
