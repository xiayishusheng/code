/*
*	�Ӽ��̶�ȡһ���ַ�������0~9���ַ�������������ַ�����ǰ�棬���ı�ԭ�е�˳��
*	���磺����	hello12345world!
*	�����		helloworld!12345
*/

//���������Լ���ķ������ǰ��ַ�����0~9���ַ���tempnum���������ķ���tempchar�У�����tempnum�ӵ�temchar���档

#include "stdio.h"
int main()
{
	//���������ַ���
	char str[128];
	int i=0;
	//��Ž���0~9���ַ�
	char tempnum[128];
	int k=0;
	//����ַ������ַ�
	char tempchar[128];
	int j=0;

	printf("�����ַ�����");
	gets(str);
	//scanf("%s",str);

	for(i=0; i<strlen(str); i++)
	{		
		if(str[i]>='0' && str[i]<='9')
		{//�����0~9���ַ�������tempnum��
			tempnum[j]=str[i];
			j++;
		}
		else
		{//����������ַ�������tempchar��
			tempchar[k]=str[i];
			k++;
		}
	}

	tempnum[j]='\0';
	tempchar[k]='\0';
	//��tempnum׷�ӵ�tempchar����
	strcat(tempchar,tempnum);

	printf("����ַ�����%s\n",tempchar);
	system("pause");
}
