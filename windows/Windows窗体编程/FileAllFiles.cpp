// FileAllFiles.cpp
// 功能：遍历目录下的文件和目录

#include "stdafx.h"
#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

//以下是算法伪代码：
//void EnumerateFileInDrectory(LPCTSTR lpszPath)
//{
//  开始查找;
//  if (没有找到文件)
//    return;
//  do
//  {
//    if (找到的文件是目录)
//      function(找到的目录);
//    else
//      对文件进行操作;
//  } while (查找下一个文件并成功);
//}


/* **********************************************
* DWORD EnumerateFileInDrectory(LPSTR szPath)
* 功能：	遍历目录下的文件和目录，将显示文件的文件和文件夹隐藏、加密的属性
* 参数：	LPTSTR szPath，为需遍历的路径
* 返回值：	0代表执行完成，1代码发生错误
* ********************************************* */
DWORD EnumerateFileInDrectory(LPSTR szPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hListFile;
	CHAR szFilePath[MAX_PATH];

	//构造代表子目录和文件夹路径的字符串
	strcpy(szFilePath, szPath);
	//查找所有文件
	strcat(szFilePath, "\\*");
	printf("%s\n", szFilePath);
	//查找第一个文件/目录，获得查找句柄
	hListFile = FindFirstFile(szFilePath, &FindFileData);
	//判断句柄
	if(hListFile==INVALID_HANDLE_VALUE)
	{
		printf("错误：%d",GetLastError());
		return 1;
	}
	else
	{
		do
		{
			// 不显示代表本级目录和上级目录的“.”和“..”
			if(lstrcmp(FindFileData.cFileName,TEXT("."))==0||
				lstrcmp(FindFileData.cFileName,TEXT(".."))==0)
			{
				continue;
			}

			//打印文件名、目录名
			printf("%s\t\t",FindFileData.cFileName);
			//判断文件属性，加密文件或文件夹
			if(FindFileData.dwFileAttributes&FILE_ATTRIBUTE_ENCRYPTED)
			{
				printf("<加密> ");
			}
			//判断文件属性，隐藏文件或文件夹
			if(FindFileData.dwFileAttributes&FILE_ATTRIBUTE_HIDDEN)
			{
				printf("<隐藏> ");
			}
			//判断文件属性，目录
			if(FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
			{
				printf("<DIR> ");
			}
			//读者可根据文件属性表中的内容自行添加判断文件属性。
			printf("\n");
		}
		while(FindNextFile(hListFile, &FindFileData));
	}
	return 0;
}


/* **********************************************
* int main(int argc, char argv[])
* 功能：	调用EnumerateFileInDrectory遍历目录下的文件和目录
* 参数：	argv[1]为需遍历的路径，如果为空则获取当前路径
* ******************************************** */
int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		EnumerateFileInDrectory(argv[1]);
	}
	else
	{
		CHAR szCurrentPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, szCurrentPath);
		EnumerateFileInDrectory(szCurrentPath);
	}

	return 0;
}