#include "stdio.h"

/* **************************************************
 *	本算法实现：
 *	求 1- 1/2 + 1/3 -1/4 + ... + 1/99 - 1/100 的值
 *	
 *	结果为：0.688172
 * **************************************************/
int denominator(int num)
{
    int sign = 1;
    int deno = 2;
    float temp = 0;
    float sum = 1.0;

    while (deno <= num)
    {
        sign *= -1;
        temp = 1.0/(deno*sign);
        sum = sum + temp;
        deno += 1;
    }
    printf("The result 1- 1/2 + 1/3 -1/4 + ... + 1/99 - 1/100 = %f\n",sum);
    return 0;
}

/* **************************************************
 *	实现求三个数中的最大数
 * **************************************************/
int max_three(int a, int b, int c)
{
    int tmp, max;
    tmp = a > b ? a : b;
    max = tmp > c ? tmp : c;
    return max;
}

int main(int argc, char* argv[])
{
    int a = 23, b = 54, c = 44;
    printf("Max number is : %d \n", max_three(a, b, c));
    denominator(100);
    return 0;
}
