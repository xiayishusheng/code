/*
	猜数字：出题者在0~9中任选不重复的四个数排列成四位数，
然后让猜数者每次通过从0~9中任选四个数字来猜使用的是哪四
个数字和这四个数字各在那个位置。如果数字正确但位置错误就
用B表示，如果数字正确位置正确就用A表示。知道猜出正确答案，
即结果为4A0B。
*/
//guess.cpp

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int answer[4]={1,3,5,2};							//初始化结果为1352
	int guess;											//玩家猜测的答案
	int times=0;										//猜测次数初始化为0
	int a=0;											//数字正确；位置正确 的个数
	int b=0;											//数字正确；位置错误 的个数
	int i,j;

	printf("please input your guess number:\n");

	/*** ===进入猜数字循环=== ***/
	while(a!=4)
	{
		a=0;											//每次猜测前设定a、b都为0
		b=0;
		times++;										//猜测次数加1

		printf("%d	",times);							//显示猜测次数
		scanf("%d",&guess);								//从键盘读取本次猜测的四位数字

		/** ==进入猜测答案和正确答案对比循环== **/
		for(i=3;i>-1;i--)								//被猜数从10的3次方开始整除，以取得最高位值，一直除到0次方
		{
			for(j=0;j<4;j++)							//真实答案从最高位开始取（数组最前面），直到数组最后
			{
				if((int)(guess/pow(10,i))==answer[j])	//比对每一位猜测数字,比较两者相应位是否相等
				{
					if(i+j==3)							//比较两者所取的当前位置是否是同位，如果位置相同a加1
						a+=1;
					else
						b=b+1;							//如果位置不同b加1
				}
			}
			guess-=(int)(guess/pow(10,i))*pow(10,i);	//被猜数舍去当前最高位，然后比对下一位猜测数字
		}
		printf("	%dA%dB\n",a,b);						//显示本次猜测的a、b正确性
	}
	return 0;
}
