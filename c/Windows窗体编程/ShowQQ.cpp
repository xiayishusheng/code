// ShowQQ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Windows.h"


int _tmain(int argc, _TCHAR* argv[])
{

	HWND hd=::FindWindow(NULL,"QQ2013");
	::ShowWindow(hd,SW_SHOWNA);

	return 0;
}

