// rectangel.cpp : Defines the entry point for the console application.
// 构造函数例子

#include "stdafx.h"
#include <iostream>
using namespace std;

class rectangel
{
public:
	rectangel(int l,int w)
	{
		length=l;
		width=w;
	}
	
	int area()
	{
		return length*width;
	}
	
private:
	int length;
	int width;
};

int main(int argc, char* argv[])
{
	rectangel rec(3,4);
	cout<<"长方形rec的面积为："<<rec.area()<<endl;
	return 0;
}

