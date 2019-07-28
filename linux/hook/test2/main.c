#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("enter main...\n");

    int *p = (int *)malloc(10);
    if (!p) {
        printf("allocation error...\n");
        exit(1);
    }

    printf("returning to main...\n");

    free(p);

    if (strcmp("aa", "bb") == 0)
    {
        printf("hook strcmp\n");
    }
    else
    {
        printf("not match\n");
    }

    return 0;
}
