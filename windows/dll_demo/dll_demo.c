#include <stdio.h>

__declspec( dllexport ) int add(int a, int b)
{
    printf("calling add\n");
    return a + b;
}
