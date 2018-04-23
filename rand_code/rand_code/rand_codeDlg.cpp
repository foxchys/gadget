
// rand_codeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "rand_code.h"
#include "rand_codeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Crand_codeDlg dialog



Crand_codeDlg::Crand_codeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RAND_CODE_DIALOG, pParent)
	, m_number(0)
	, m_times(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Crand_codeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_number);
	DDX_Control(pDX, IDC_EDIT2, m_randcode);
	DDX_Text(pDX, IDC_EDIT3, m_times);
}

BEGIN_MESSAGE_MAP(Crand_codeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &Crand_codeDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Crand_codeDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Crand_codeDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Crand_codeDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Crand_codeDlg::OnBnClickedButton5)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &Crand_codeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Crand_codeDlg message handlers

BOOL Crand_codeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	srand((unsigned)time(NULL));
	codenumber = 0;
	interval_times = 0;
	m_times = 0;
	m_number = 0;
	GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("设定乱码个数"));
	GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("设定间隔时间"));
	GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("生成一组乱码"));
	GetDlgItem(IDC_BUTTON4)->SetWindowTextW(_T("打开自动"));
	GetDlgItem(IDC_BUTTON3)->SetWindowTextW(_T("清空生成区"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Crand_codeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Crand_codeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Crand_codeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Crand_codeDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	std::string newrandcode;
	if (!codenumber)
	{
		AfxMessageBox(_T("请先设定大于0的乱码个数！"));
		return;
	}
	else
	{
		std::vector <int> asciicode;
		std::vector <char> realcode;
		//srand((unsigned)time(NULL));
		for (int i = 0; i < codenumber; i++)
		{
			int randzzz;
			randzzz = 1 + rand() % (3 + 1 - 1);
			switch (randzzz)
			{
			case(1):
				asciicode.push_back((rand() % (57 - 48 + 1)) + 48);
				break;
			case(2):
				asciicode.push_back((rand() % (90 - 65 + 1)) + 65);
				break;
			case(3):
				asciicode.push_back((rand() % (122 - 97 + 1)) + 97);
			default:
				break;
			}
		}
		for (int i = 0; i < codenumber; i++)
		{
			int tempp = asciicode[i];
			char temp = tempp;
			realcode.push_back(temp);
		}
		for (int i = 0; i < codenumber; i++)
		{
			newrandcode += realcode[i];
		}
		int lastline;
		if (m_randcode.LineIndex(m_randcode.GetLineCount() - 1) > 256* codenumber)
			m_randcode.SetWindowTextW(_T(""));
		lastline = m_randcode.LineIndex(m_randcode.GetLineCount() - 1);
		m_randcode.SetSel(lastline + 1, lastline + 2, 1);
		newrandcode += "\n";
		CString newreplace;
		newreplace = newrandcode.c_str();
		m_randcode.ReplaceSel(newreplace);
		if (CopyToClipboard(newrandcode))
			return;
	}
	return;
}

//BOOL Crand_codeDlg::CopyToClipboard(const char* pszData, const int nDataLen)
//{
//	if (::OpenClipboard(NULL))//打开剪贴板  
//	{
//		::EmptyClipboard();//清空剪贴板
//		HGLOBAL clipbuffer;
//		char *buffer;
//		//写入数据 
//		clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen + 1);
//		buffer = (char *)::GlobalLock(clipbuffer);
//		strcpy(buffer, pszData);
//		::GlobalUnlock(clipbuffer);//解锁  
//		::SetClipboardData(CF_TEXT, clipbuffer);//设置格式
//		//关闭剪贴板  
//		::CloseClipboard();
//		return TRUE;
//	}
//	return FALSE;
//}

BOOL Crand_codeDlg::CopyToClipboard(std::string pszData)
{
	if (::OpenClipboard(NULL))//打开剪贴板  
	{
		::EmptyClipboard();//清空剪贴板
		HGLOBAL clipbuffer;
		char *buffer;
		//写入数据 
		clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, pszData.size() + 1);
		buffer = (char *)::GlobalLock(clipbuffer);
		strcpy_s(buffer, pszData.size() + 1, pszData.c_str());
		::GlobalUnlock(clipbuffer);//解锁  
		::SetClipboardData(CF_TEXT, clipbuffer);//设置格式
												//关闭剪贴板  
		::CloseClipboard();
		return TRUE;
	}
	return FALSE;
}

void Crand_codeDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	srand((unsigned)time(NULL));
	CString temp;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(temp);
	codenumber = _tstoi(temp);
	if (codenumber == 9527)
		AfxMessageBox(_T("What a fool!"));
	if (!(codenumber > 0))
	{
		AfxMessageBox(_T("请输入大于0的整数！"));
		return;
	}
	temp.Format(_T("设定生成乱码为%d个！"), codenumber);
	AfxMessageBox(temp);
	return;
}


void Crand_codeDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(_T(""));
}


void Crand_codeDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	if (!codenumber)
	{
		AfxMessageBox(_T("请先设定大于0的乱码个数！"));
		return;
	}
	if (!interval_times)
	{
		AfxMessageBox(_T("请先设定大于0的乱码生成间隔时间！"));
		return;
	}
	CString temp;
	GetDlgItem(IDC_BUTTON4)->GetWindowTextW(temp);
	if (temp == "打开自动")
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT1)->EnableWindow(false);
		GetDlgItem(IDC_EDIT3)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON4)->SetWindowTextW(_T("关闭自动"));
		SetTimer(1, interval_times, NULL);
	}
	else
	{
		GetDlgItem(IDC_BUTTON4)->SetWindowTextW(_T("打开自动"));
		KillTimer(1);
		GetDlgItem(IDC_EDIT1)->EnableWindow(true);
		//GetDlgItem(IDC_EDIT3)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
	}
}


void Crand_codeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case(1):
		OnBnClickedButton2();
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void Crand_codeDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	srand((unsigned)time(NULL));
	CString temp;
	GetDlgItem(IDC_EDIT3)->GetWindowTextW(temp);
	interval_times = _tstoi(temp);
	if (!(interval_times > 0))
	{
		AfxMessageBox(_T("请输入大于0的整数！"));
		return;
	}
	temp.Format(_T("设定自动生成乱码间隔时间为%dms！"), interval_times);
	AfxMessageBox(temp);
	return;
}


void Crand_codeDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_times = 0;
	m_number = 0;
	UpdateData(false);
	CDialogEx::OnOK();
}
