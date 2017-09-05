
// OpenQQ_ShowQQDlg.cpp : 实现文件
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// COpenQQ_ShowQQDlg 对话框




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


// COpenQQ_ShowQQDlg 消息处理程序

BOOL COpenQQ_ShowQQDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//::SetWindowLongA(this->m_hWnd,GWL_EXSTYLE,WS_EX_TOOLWINDOW|WS_EX_DLGMODALFRAME);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COpenQQ_ShowQQDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR COpenQQ_ShowQQDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COpenQQ_ShowQQDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//WinExec(_T("C:\\Program Files\\Tencent\\QQ\\bin\\QQ.exe"),SW_SHOWNORMAL);
	
	//PROCESS_INFORMATION pi;
	//STARTUPINFO si;
	memset(&si1,0,sizeof(si1));
	si1.cb=sizeof(si1);
	si1.wShowWindow=SW_SHOW;
	si1.dwFlags=STARTF_USESHOWWINDOW;
	
	bool fRet = CreateProcess(
		//"C:\\Program Files\\Tencent\\QQ\\bin\\QQ.exe"	//执行程序的名称
		"C:\\Windows\\System32\\notepad.exe"			//执行程序的名称
		,NULL											//参数行
		,NULL											//进程的安全属性，如果为NULL则使用默认的安全属性
		,FALSE											//线程的安全属性，如果为NULL则使用默认的安全属性
		,NULL											//继承标志
		,NULL											//创建标志
		,NULL											//环境变量
		,NULL											//运行该进程的初始目录
		,&si1											//用于在创建子进程时设置各种属性
		,&pi1);											//用于在进程创建后接受相关信息

}

/*
在上面的参数中，使用了两个比较重要的数据结构：STARTUPINFO和PROCESS_INFORMATION。这两个结构的定义分别如下：

typedef struct _STARTUPINFO { // si
DWORD cb; //结构长度
LPTSTR lpReserved; //保留
LPTSTR lpDesktop; //保留
LPTSTR lpTitle; //如果为控制台进程则为显示的标题
DWORD dwX; //窗口横坐标
DWORD dwY; //窗口丛坐标
DWORD dwXSize; //窗口宽度
DWORD dwYSize; //窗口高度
DWORD dwXCountChars; //控制台窗口字符号宽度
DWORD dwYCountChars; //控制台窗口字符号高度
DWORD dwFillAttribute; //控制台窗口填充模式
DWORD dwFlags; //创建标记
WORD wShowWindow; //窗口显示标记，如同ShowWindow中的标记


WORD cbReserved2; //保留参数
LPBYTE lpReserved2; //保留参数
HANDLE hStdInput; //标准输入句柄
HANDLE hStdOutput; //标准输出句柄
HANDLE hStdError; //标准错误句柄
} STARTUPINFO, *LPSTARTUPINFO;

typedef struct _PROCESS_INFORMATION { // pi
HANDLE hProcess; //进程句柄
HANDLE hThread; //进程的主线程句柄
DWORD dwProcessId; //进程的ID
DWORD dwThreadId; //进程的主线程ID
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
         // 注意：当查找到了，应该返回FALSE中止枚举下去
         return FALSE;
     }
     return TRUE;//继续枚举下去直到所有顶层窗口枚举完为止

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
	//HWND QQWindow = ::FindWindow("Notepad", "无标题 - 记事本");
	//HWND QQWindow = ::FindWindowEx(NULL, NULL, "TXGuiFoundation", "QQ2013");
	::ShowWindow(QQWindow, SW_SHOWNORMAL);//还原窗口
}


void COpenQQ_ShowQQDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	memset(&si2,0,sizeof(si2));
	si2.cb=sizeof(si2);
	si2.wShowWindow=SW_SHOW;
	si2.dwFlags=STARTF_USESHOWWINDOW;
	
	bool fRet = CreateProcess(
		//"C:\\Program Files\\Tencent\\QQ\\bin\\QQ.exe"	//执行程序的名称
		//"C:\\Program Files\\MSN Messenger\\msnmsgr.exe"
		"C:\\Windows\\System32\\notepad.exe"			//执行程序的名称
		,NULL											//参数行
		,NULL											//进程的安全属性，如果为NULL则使用默认的安全属性
		,FALSE											//线程的安全属性，如果为NULL则使用默认的安全属性
		,NULL											//继承标志
		,NULL											//创建标志
		,NULL											//环境变量
		,NULL											//运行该进程的初始目录
		,&si2											//用于在创建子进程时设置各种属性
		,&pi2);											//用于在进程创建后接受相关信息
}


void COpenQQ_ShowQQDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//HWND QQWindow = ::FindWindow("MSBLWindowClass", "MSN Messenger");
	//HWND QQWindow = ::FindWindow("MSBLWindowClass", "MSN Messenger");
	HWND QQWindow = myGetWindowByProcessId(pi2.dwProcessId);
	::ShowWindow(QQWindow, SW_SHOWNORMAL);//还原窗口
}


void COpenQQ_ShowQQDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	memset(&si3,0,sizeof(si3));
	si3.cb=sizeof(si3);
	si3.wShowWindow=SW_SHOW;
	si3.dwFlags=STARTF_USESHOWWINDOW;
	
	bool fRet = CreateProcess(
		"C:\\Program Files\\Tencent\\QQ\\bin\\QQ.exe"	//执行程序的名称
		//"C:\\Windows\\System32\\notepad.exe"			//执行程序的名称
		,NULL											//参数行
		,NULL											//进程的安全属性，如果为NULL则使用默认的安全属性
		,FALSE											//线程的安全属性，如果为NULL则使用默认的安全属性
		,NULL											//继承标志
		,NULL											//创建标志
		,NULL											//环境变量
		,NULL											//运行该进程的初始目录
		,&si3											//用于在创建子进程时设置各种属性
		,&pi3);											//用于在进程创建后接受相关信息
	
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
	::ShowWindow(QQWindow, SW_SHOWNORMAL);//还原窗口
	::MessageBox(NULL, a, "===", MB_OK);
}
