
// Open_Show_AppDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Open_Show_App.h"
#include "Open_Show_AppDlg.h"
#include "afxdialogex.h"

#include "tlhelp32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// COpen_Show_AppDlg �Ի���




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


// COpen_Show_AppDlg ��Ϣ�������

BOOL COpen_Show_AppDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COpen_Show_AppDlg::OnPaint()
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	//::ShowWindow(h, SW_SHOWNA);//��ԭ����

	EnumWindows(EnumWindowsProc2, (LPARAM)this);
}
