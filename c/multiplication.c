#include <stdio.h>
#include <unistd.h>

void multiplication(int num)
{
	int i,j;
	for(i = 1; i <= num; i++)
	{
		for(j = 1; j <= i; j++)
		{
			printf("%d * %d = %d\t", j, i, j * i);
		}
		printf("\n");
	}
}

int main(int argv, char *args[])
{
    //sleep(3);
	multiplication(9);
	return 0;
}
