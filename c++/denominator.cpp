/*
	本算法实现：
	求 1- 1/2 + 1/3 -1/4 + ... + 1/99 - 1/100 的值
	
	结果为：0.688172
*/

#include "stdafx.h"
#include "stdio.h"

#define MAX 100

int main(int argc, char* argv[])
{
	int sign = 1;
	int deno = 2;
	float temp = 0;
	float sum = 1.0;
	
	while (deno <= MAX)
	{
		sign *= -1;
		temp = 1.0/(deno*sign);
		sum = sum + temp;
		deno += 1;
	}
	printf("The result is : %f\n",sum);
	return 0;
}
