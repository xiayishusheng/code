#include <stdio.h>
int main()
{
    struct bar
    {
        int i;
        long j;
        int k;
        char *p;
    }BAR_TEST;

    struct bar2
    {
        char *p;
        long j;
        int i;
        int k;
    }BAR_TEST2;

    printf ("char %ld \n", sizeof(char));
    printf ("short %ld \n", sizeof(short));
    printf ("int %ld \n", sizeof(int));
    printf ("long %ld \n", sizeof(long));
    printf ("long long %ld \n", sizeof(long long));
    printf ("float %ld \n", sizeof(float));
    printf ("double %ld \n", sizeof(double));
    printf ("long double %ld \n", sizeof(long double));
    printf ("pointer %ld \n", sizeof(void*));
    printf ("bar size %ld \n", sizeof(BAR_TEST));
    printf ("bar size %ld \n", sizeof(BAR_TEST2));

    return 0;
}
