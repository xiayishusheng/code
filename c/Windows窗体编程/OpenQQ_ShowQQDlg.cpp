
// OpenQQ_ShowQQDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OpenQQ_ShowQQ.h"
#include "OpenQQ_ShowQQDlg.h"
#include "afxdialogex.h"

#include "Windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

PROCESS_INFORMATION pi1;
STARTUPINFO si1;

PROCESS_INFORMATION pi2;
STARTUPINFO si2;

PROCESS_INFORMATION pi3;
STARTUPINFO si3;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COpenQQ_ShowQQDlg �Ի���




COpenQQ_ShowQQDlg::COpenQQ_ShowQQDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpenQQ_ShowQQDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenQQ_ShowQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenQQ_ShowQQDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &COpenQQ_ShowQQDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COpenQQ_ShowQQDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &COpenQQ_ShowQQDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &COpenQQ_ShowQQDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &COpenQQ_ShowQQDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &COpenQQ_ShowQQDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// COpenQQ_ShowQQDlg ��Ϣ�������

BOOL COpenQQ_ShowQQDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//::SetWindowLongA(this->m_hWnd,GWL_EXSTYLE,WS_EX_TOOLWINDOW|WS_EX_DLGMODALFRAME);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void COpenQQ_ShowQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COpenQQ_ShowQQDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COpenQQ_ShowQQDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COpenQQ_ShowQQDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//WinExec(_T("C:\\Program Files\\Tencent\\QQ\\bin\\QQ.exe"),SW_SHOWNORMAL);
	
	//PROCESS_INFORMATION pi;
	//STARTUPINFO si;
	memset(&si1,0,sizeof(si1));
	si1.cb=sizeof(si1);
	si1.wShowWindow=SW_SHOW;
	si1.dwFlags=STARTF_USESHOWWINDOW;
	
	bool fRet = CreateProcess(
		//"C:\\Program Files\\Tencent\\QQ\\bin\\QQ.exe"	//ִ�г��������
		"C:\\Windows\\System32\\notepad.exe"			//ִ�г��������
		,NULL											//������
		,NULL											//���̵İ�ȫ���ԣ����ΪNULL��ʹ��Ĭ�ϵİ�ȫ����
		,FALSE											//�̵߳İ�ȫ���ԣ����ΪNULL��ʹ��Ĭ�ϵİ�ȫ����
		,NULL											//�̳б�־
		,NULL											//������־
		,NULL											//��������
		,NULL											//���иý��̵ĳ�ʼĿ¼
		,&si1											//�����ڴ����ӽ���ʱ���ø�������
		,&pi1);											//�����ڽ��̴�������������Ϣ

}

/*
������Ĳ����У�ʹ���������Ƚ���Ҫ�����ݽṹ��STARTUPINFO��PROCESS_INFORMATION���������ṹ�Ķ���ֱ����£�

typedef struct _STARTUPINFO { // si
DWORD cb; //�ṹ����
LPTSTR lpReserved; //����
LPTSTR lpDesktop; //����
LPTSTR lpTitle; //���Ϊ����̨������Ϊ��ʾ�ı���
DWORD dwX; //���ں�����
DWORD dwY; //���ڴ�����
DWORD dwXSize; //���ڿ��
DWORD dwYSize; //���ڸ߶�
DWORD dwXCountChars; //����̨�����ַ��ſ��
DWORD dwYCountChars; //����̨�����ַ��Ÿ߶�
DWORD dwFillAttribute; //����̨�������ģʽ
DWORD dwFlags; //�������
WORD wShowWindow; //������ʾ��ǣ���ͬShowWindow�еı��


WORD cbReserved2; //��������
LPBYTE lpReserved2; //��������
HANDLE hStdInput; //��׼������
HANDLE hStdOutput; //��׼������
HANDLE hStdError; //��׼������
} STARTUPINFO, *LPSTARTUPINFO;

typedef struct _PROCESS_INFORMATION { // pi
HANDLE hProcess; //���̾��
HANDLE hThread; //���̵����߳̾��
DWORD dwProcessId; //���̵�ID
DWORD dwThreadId; //���̵����߳�ID
} PROCESS_INFORMATION;
*/

typedef struct EnumFunArg
{
     HWND hWnd;
     DWORD dwProcessId;

}EnumFunArg;


BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam)
{

     EnumFunArg *pArg = reinterpret_cast<EnumFunArg *> (lParam);
     DWORD  dwProcessId;
     GetWindowThreadProcessId(hwnd, &dwProcessId);
     if( dwProcessId == pArg->dwProcessId )
     {
         pArg->hWnd = hwnd;
         // ע�⣺�����ҵ��ˣ�Ӧ�÷���FALSE��ֹö����ȥ
         return FALSE;
     }
     return TRUE;//����ö����ȥֱ�����ж��㴰��ö����Ϊֹ

}

HWND myGetWindowByProcessId( DWORD dwProcessId )
{
     EnumFunArg arg;
     arg.dwProcessId = dwProcessId;
     arg.hWnd = 0;
     EnumWindows(lpEnumFunc,reinterpret_cast<LPARAM>(&arg));
     return arg.hWnd;
}

void COpenQQ_ShowQQDlg::OnBnClickedButton2()
{
	
	HWND QQWindow = myGetWindowByProcessId(pi1.dwProcessId);
	//GetWindowThreadProcessId(NULL,NULL);
	//HWND QQWindow = ::FindWindow("Notepad", "�ޱ��� - ���±�");
	//HWND QQWindow = ::FindWindowEx(NULL, NULL, "TXGuiFoundation", "QQ2013");
	::ShowWindow(QQWindow, SW_SHOWNORMAL);//��ԭ����
}


void COpenQQ_ShowQQDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	memset(&si2,0,sizeof(si2));
	si2.cb=sizeof(si2);
	si2.wShowWindow=SW_SHOW;
	si2.dwFlags=STARTF_USESHOWWINDOW;
	
	bool fRet = CreateProcess(
		//"C:\\Program Files\\Tencent\\QQ\\bin\\QQ.exe"	//ִ�г��������
		//"C:\\Program Files\\MSN Messenger\\msnmsgr.exe"
		"C:\\Windows\\System32\\notepad.exe"			//ִ�г��������
		,NULL											//������
		,NULL											//���̵İ�ȫ���ԣ����ΪNULL��ʹ��Ĭ�ϵİ�ȫ����
		,FALSE											//�̵߳İ�ȫ���ԣ����ΪNULL��ʹ��Ĭ�ϵİ�ȫ����
		,NULL											//�̳б�־
		,NULL											//������־
		,NULL											//��������
		,NULL											//���иý��̵ĳ�ʼĿ¼
		,&si2											//�����ڴ����ӽ���ʱ���ø�������
		,&pi2);											//�����ڽ��̴�������������Ϣ
}


void COpenQQ_ShowQQDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//HWND QQWindow = ::FindWindow("MSBLWindowClass", "MSN Messenger");
	//HWND QQWindow = ::FindWindow("MSBLWindowClass", "MSN Messenger");
	HWND QQWindow = myGetWindowByProcessId(pi2.dwProcessId);
	::ShowWindow(QQWindow, SW_SHOWNORMAL);//��ԭ����
}


void COpenQQ_ShowQQDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	memset(&si3,0,sizeof(si3));
	si3.cb=sizeof(si3);
	si3.wShowWindow=SW_SHOW;
	si3.dwFlags=STARTF_USESHOWWINDOW;
	
	bool fRet = CreateProcess(
		"C:\\Program Files\\Tencent\\QQ\\bin\\QQ.exe"	//ִ�г��������
		//"C:\\Windows\\System32\\notepad.exe"			//ִ�г��������
		,NULL											//������
		,NULL											//���̵İ�ȫ���ԣ����ΪNULL��ʹ��Ĭ�ϵİ�ȫ����
		,FALSE											//�̵߳İ�ȫ���ԣ����ΪNULL��ʹ��Ĭ�ϵİ�ȫ����
		,NULL											//�̳б�־
		,NULL											//������־
		,NULL											//��������
		,NULL											//���иý��̵ĳ�ʼĿ¼
		,&si3											//�����ڴ����ӽ���ʱ���ø�������
		,&pi3);											//�����ڽ��̴�������������Ϣ
	
	if (fRet) 
	{
		CloseHandle(pi3.hProcess);
		CloseHandle(pi3.hThread);
	}
}


void COpenQQ_ShowQQDlg::OnBnClickedButton6()
{
	HWND QQWindow = myGetWindowByProcessId(pi3.dwProcessId);
	
	char a[64]={0x00};
	sprintf(a,"pi3.dwProcessId=%d\n",pi3.dwProcessId);
	::ShowWindow(QQWindow, SW_SHOWNORMAL);//��ԭ����
	::MessageBox(NULL, a, "===", MB_OK);
}
