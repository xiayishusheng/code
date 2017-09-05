// FindParentPid.cpp
// 功能：获取指定进程的父进程id

// NTDLL.DLL中有一个函数叫NtQueryInformationProcess，
// 用它可以将指定类型的进程信息拷贝到某个缓冲区。
// 其原型如下：
/*
	NTSYSAPI
	NTSTATUS
	NTAPI
	NtQueryInformationProcess (
	IN HANDLE ProcessHandle,				// handle to process	进程句柄
	IN PROCESSINFOCLASS InformationClass,	// information type		信息类型
	OUT PVOID ProcessInformation,			// pointer to buffer	缓冲指针
	IN ULONG ProcessInformationLength,		// buffer size in bytes	以字节为单位的缓冲大小
	OUT PULONG ReturnLength OPTIONAL		// pointer to a 32-bit variable that receives the number of bytes written to the buffer	写入缓冲的字节数
	);
		第一个参数是希望操作的进程句柄，这个句柄必须以PROCESS_QUERY_INFORMATION模式存取。
	为了取得一个句柄，我们必须用OpenProcess函数：
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,dwProcessID);
		第二个参数是请求信息的类型，这个参数可以有许多个值，本例中将使用ProcessBasicInformation(值为0)。
	因此，如果第二个参数是ProcessBasicInformation的话，则第三个参数必须为一个指针指向结构
	PROCESS_BASIC_INFORMATION：
	typedef struct
	{
		DWORD ExitStatus;			// 接收进程终止状态
		DWORD PebBaseAddress;		// 接收进程环境块地址
		DWORD AffinityMask;			// 接收进城关联掩码
		DWORD BasePriority;			// 接收进城的优先级类
		ULONG UniqueProcessId;		// 接收进程ID
		ULONG InheritedFromUniqueProcessId;	// 接收父进程ID
	} PROCESS_BASIC_INFORMATION;
	这个结构的最后一个参数是InheritedFromUniqueProcessId，就是我们想要的东西。

	DWORD dwParentPID;
	LONG status;
	PROCESS_BASIC_INFORMATION pbi;
	status = NtQueryInformationProcess( hProcess,
	ProcessBasicInformation,
	(PVOID)&pbi,
	sizeof(PROCESS_BASIC_INFORMATION),
	NULL );
	if (!status)
	dwParentPID = pbi.InheritedFromUniqueProcessId;
*/


#include "stdafx.h"
#include <windows.h>   
#include <stdio.h>

#define ProcessBasicInformation 0

typedef struct
{
	DWORD ExitStatus;
	DWORD PebBaseAddress;
	DWORD AffinityMask;
	DWORD BasePriority;
	ULONG UniqueProcessId;
	ULONG InheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION;

typedef LONG (WINAPI *PROCNTQSIP)(HANDLE,UINT,PVOID,ULONG,PULONG);
PROCNTQSIP NtQueryInformationProcess;  
DWORD GetParentProcessID(DWORD dwId);

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc<2)  
    {  
       printf("Usage:\n\n parent.exe ProcessId \n");
       return 1;  
    }
    NtQueryInformationProcess = (PROCNTQSIP)GetProcAddress(GetModuleHandle("ntdll"),"NtQueryInformationProcess");
    if (!NtQueryInformationProcess)  
       return 1;
    DWORD dwId;  
    sscanf(argv[1],"%lu",&dwId);
    printf("Parent PID for %lu is %lu\n", dwId, GetParentProcessID(dwId));
	return 0;
}

DWORD GetParentProcessID(DWORD dwId)
{
	LONG                      status;
	DWORD                     dwParentPID = (DWORD)-1;
	HANDLE                    hProcess;
	PROCESS_BASIC_INFORMATION pbi;
	// Get process handle 获取进程句柄
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,dwId);
	if (!hProcess)
		return (DWORD)-1;

	// Retrieve information 检索进程信息
	status = NtQueryInformationProcess( hProcess,  
                                        ProcessBasicInformation,  
                                        (PVOID)&pbi,  
                                        sizeof(PROCESS_BASIC_INFORMATION),  
                                        NULL );

    // Copy parent Id on success 如果成功就取得父进程id
	if  (!status)
		dwParentPID = pbi.InheritedFromUniqueProcessId;
	
	CloseHandle (hProcess);
	
	return dwParentPID;  
}