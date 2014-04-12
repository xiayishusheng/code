// FindParentPid.cpp
// ���ܣ���ȡָ�����̵ĸ�����id

// NTDLL.DLL����һ��������NtQueryInformationProcess��
// �������Խ�ָ�����͵Ľ�����Ϣ������ĳ����������
// ��ԭ�����£�
/*
	NTSYSAPI
	NTSTATUS
	NTAPI
	NtQueryInformationProcess (
	IN HANDLE ProcessHandle,				// handle to process	���̾��
	IN PROCESSINFOCLASS InformationClass,	// information type		��Ϣ����
	OUT PVOID ProcessInformation,			// pointer to buffer	����ָ��
	IN ULONG ProcessInformationLength,		// buffer size in bytes	���ֽ�Ϊ��λ�Ļ����С
	OUT PULONG ReturnLength OPTIONAL		// pointer to a 32-bit variable that receives the number of bytes written to the buffer	д�뻺����ֽ���
	);
		��һ��������ϣ�������Ľ��̾����������������PROCESS_QUERY_INFORMATIONģʽ��ȡ��
	Ϊ��ȡ��һ����������Ǳ�����OpenProcess������
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,dwProcessID);
		�ڶ���������������Ϣ�����ͣ������������������ֵ�������н�ʹ��ProcessBasicInformation(ֵΪ0)��
	��ˣ�����ڶ���������ProcessBasicInformation�Ļ������������������Ϊһ��ָ��ָ��ṹ
	PROCESS_BASIC_INFORMATION��
	typedef struct
	{
		DWORD ExitStatus;			// ���ս�����ֹ״̬
		DWORD PebBaseAddress;		// ���ս��̻������ַ
		DWORD AffinityMask;			// ���ս��ǹ�������
		DWORD BasePriority;			// ���ս��ǵ����ȼ���
		ULONG UniqueProcessId;		// ���ս���ID
		ULONG InheritedFromUniqueProcessId;	// ���ո�����ID
	} PROCESS_BASIC_INFORMATION;
	����ṹ�����һ��������InheritedFromUniqueProcessId������������Ҫ�Ķ�����

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
	// Get process handle ��ȡ���̾��
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,dwId);
	if (!hProcess)
		return (DWORD)-1;

	// Retrieve information ����������Ϣ
	status = NtQueryInformationProcess( hProcess,  
                                        ProcessBasicInformation,  
                                        (PVOID)&pbi,  
                                        sizeof(PROCESS_BASIC_INFORMATION),  
                                        NULL );

    // Copy parent Id on success ����ɹ���ȡ�ø�����id
	if  (!status)
		dwParentPID = pbi.InheritedFromUniqueProcessId;
	
	CloseHandle (hProcess);
	
	return dwParentPID;  
}