#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void chengfa(int row)
{
	int i,j;
	for(i=1; i<=row; i++)
	{
		for(j=1; j<=i; j++)
		{
			printf("%d * %d = %d\t", j, i, j*i);
		}
		printf("\n");
	}
}

int is_digit(const char *str)
{
        size_t len = strlen(str);
        while(len > 0) {
                if (*str < '0' || *str > '9') {
                        return 0;
                }
                str++;
                len--;
        }
        return 1; 
}

void main(int argc, char *argv[], char **env)
{
	if(argc >= 2)
	{
		if(1 == is_digit(argv[1]))
		{
			chengfa(atoi(argv[1]));
		}
		else
		{
			printf("Illegal arguments,the argument must be a number!\n");
		}
	}
	else
	{
		printf("You should input at least one argument!\n");
	}
}

