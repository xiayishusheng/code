// templet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

#define MAX 100

int main(int argc, char* argv[])
{
	int a,b,c;				//����һ���൱�����ó�ʼֵ
	a=1;
	b=2;
	c=3;
	while(a!='q')
	{
		printf("%d",c);		//��������൱���ػ���Ļ
		a=getch();			//���������൱����Ӧ�����豸
		c=a*b;				//�����ģ��൱�������������ֵ
	}						//�����壺���a������q �ͼ���ѭ�����������
	return 0;
}