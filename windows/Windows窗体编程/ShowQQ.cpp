// ShowQQ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Windows.h"


int _tmain(int argc, _TCHAR* argv[])
{

	HWND hd=::FindWindow(NULL,"QQ2013");
	::ShowWindow(hd,SW_SHOWNA);

	return 0;
}

