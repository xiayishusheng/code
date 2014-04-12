
// Open_Show_AppDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Open_Show_App.h"
#include "Open_Show_AppDlg.h"
#include "afxdialogex.h"

#include "tlhelp32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// COpen_Show_AppDlg 对话框




COpen_Show_AppDlg::COpen_Show_AppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpen_Show_AppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpen_Show_AppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpen_Show_AppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &COpen_Show_AppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COpen_Show_AppDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// COpen_Show_AppDlg 消息处理程序

BOOL COpen_Show_AppDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void COpen_Show_AppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COpen_Show_AppDlg::OnPaint()
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
HCURSOR COpen_Show_AppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
typedef struct
{
	 HWND hWnd;
	 DWORD dwPid;

}WNDINFO;
 
BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
 WNDINFO* pInfo = (WNDINFO*)lParam;
 DWORD dwProcessId = 0;
 GetWindowThreadProcessId(hWnd, &dwProcessId);
 
 if(dwProcessId == pInfo->dwPid)
 {
  pInfo->hWnd = hWnd;
  return FALSE;
 }
 return TRUE;
}
 
HWND GetHwndByProcessId(DWORD dwProcessId)
{
 WNDINFO info = {0};
 info.hWnd = NULL;
 info.dwPid = dwProcessId;
 EnumWindows(EnumWindowsProc, (LPARAM)&info);
 return info.hWnd;
}

void COpen_Show_AppDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND h = (HWND) 0x809DC;
	DWORD dwProcessId;
    GetWindowThreadProcessId(h, &dwProcessId);
	::ShowWindow(h, SW_SHOWNORMAL);
}

BOOL CALLBACK EnumWindowsProc2(HWND hwnd,LPARAM lParam){
	char xclass[256];
	GetClassName(hwnd,xclass,sizeof(xclass));
	if(strcmp(xclass,"Notepad")==0){
		printf("Handle:%d Class:%s\n",hwnd,xclass);
		::MessageBox(NULL, "======", "====", MB_OK);
	}
	return TRUE;
}

extern "C" __declspec(dllexport) void GetNotepad(){
	EnumWindows(EnumWindowsProc2,NULL);
}

void COpen_Show_AppDlg::OnBnClickedButton2()
{
	//HWND h = ::FindWindow("TXGuiFoundation", "QQ2013");
	//DWORD dwProcessId;
	//GetWindowThreadProcessId(h, &dwProcessId);
	//::ShowWindow(h, SW_SHOWNA);//还原窗口

	EnumWindows(EnumWindowsProc2, (LPARAM)this);
}
