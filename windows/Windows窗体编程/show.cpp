// show.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Windows.h"

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam){
	
	char xclass[256];
	char xtitle[256];

	GetClassName(hwnd, xclass, sizeof(xclass));
	if(strcmp(xclass,"TXGuiFoundation") == 0){
		::GetWindowTextA(hwnd, xtitle, sizeof(xtitle));
		if (strcmp(xtitle,"QQ2013") == 0)
		{
			//printf("窗口句柄:%0x 窗体类:%s\n", hwnd, xclass);
			if( !IsWindowVisible(hwnd) )
			{
				::ShowWindow(hwnd, SW_SHOWNORMAL);
				printf("窗口句柄：%0x\n", hwnd);
				DWORD cProcessId;
				::GetWindowThreadProcessId(hwnd, &cProcessId);
				printf("进程ID：%0x\n",cProcessId);

				HWND pHwnd = ::GetParent(hwnd);
				printf("父窗口句柄：%0x\n", pHwnd);
				DWORD pProcessId;
				::GetWindowThreadProcessId(pHwnd, &pProcessId);
				printf("进程ID：%0x\n",pProcessId);
			}
			else
			{
				printf("窗体可见\n");
			}
		}
	}
	return TRUE;
}

extern "C" __declspec(dllexport) void GetQQ(){
	EnumWindows(EnumWindowsProc, NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	//HWND QQWindow = FindWindow("TXGuiFoundation", "QQ2013");
	//ShowWindow(QQWindow, SW_SHOWNA);//还原窗口

	GetQQ();

	return 0;
}

