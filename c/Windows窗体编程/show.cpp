// show.cpp : �������̨Ӧ�ó������ڵ㡣
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
			//printf("���ھ��:%0x ������:%s\n", hwnd, xclass);
			if( !IsWindowVisible(hwnd) )
			{
				::ShowWindow(hwnd, SW_SHOWNORMAL);
				printf("���ھ����%0x\n", hwnd);
				DWORD cProcessId;
				::GetWindowThreadProcessId(hwnd, &cProcessId);
				printf("����ID��%0x\n",cProcessId);

				HWND pHwnd = ::GetParent(hwnd);
				printf("�����ھ����%0x\n", pHwnd);
				DWORD pProcessId;
				::GetWindowThreadProcessId(pHwnd, &pProcessId);
				printf("����ID��%0x\n",pProcessId);
			}
			else
			{
				printf("����ɼ�\n");
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
	//ShowWindow(QQWindow, SW_SHOWNA);//��ԭ����

	GetQQ();

	return 0;
}

