/*
*	从键盘读取一个字符串，将0~9的字符放在最后，其他字符放在前面，不改变原有的顺序
*	例如：输入	hello12345world!
*	则输出		helloworld!12345
*/

//下面是我自己想的方法，是把字符串中0~9的字符放tempnum，把其他的放在tempchar中，最后把tempnum加到temchar后面。

#include "stdio.h"
int main()
{
	//存放输入的字符串
	char str[128];
	int i=0;
	//存放介于0~9的字符
	char tempnum[128];
	int k=0;
	//存放字符其他字符
	char tempchar[128];
	int j=0;

	printf("输入字符串：");
	gets(str);
	//scanf("%s",str);

	for(i=0; i<strlen(str); i++)
	{		
		if(str[i]>='0' && str[i]<='9')
		{//如果是0~9的字符则存放在tempnum中
			tempnum[j]=str[i];
			j++;
		}
		else
		{//如果是其他字符则存放在tempchar中
			tempchar[k]=str[i];
			k++;
		}
	}

	tempnum[j]='\0';
	tempchar[k]='\0';
	//将tempnum追加到tempchar后面
	strcat(tempchar,tempnum);

	printf("输出字符串：%s\n",tempchar);
	system("pause");
}
