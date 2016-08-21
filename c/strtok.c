#include <stdio.h>
#include <string.h>

int getParam(char *s2, int s3)
{
    printf("getParam\n");
    switch(s3)
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;

}

int setParam(char *s2, int s3, char *s4)
{
    printf("setParam\n");
}

int main(int argv, char *args[])
{
    if(NULL == args[1])
    {
        printf("参数为null\n");
        return -1;
    }
    char *str1 = strtok(args[1], ",");
    char *str2 = strtok(NULL, ",");
    char *str3 = strtok(NULL, ",");

    if( 0 == strcmp("get", str1) )
    {
        printf("str1=%s, str2=%s, str3=%s\n", str1, str2, str3);
        getParam(str2, str3);
    }
    else if( 0 == strcmp("set", str1) )
    {
        char *str4 = strtok(NULL, ",");
        printf("str1=%s, str2=%s, str3=%s, str4=%s\n", str1, str2, str3, str4);
        setParam(str2, atoi(str3), str4);
    }
    else
    {
        printf("error!");
    }

	return 0;
}
