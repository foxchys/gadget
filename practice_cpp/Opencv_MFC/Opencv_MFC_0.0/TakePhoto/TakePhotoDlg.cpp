
// TakePhotoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TakePhoto.h"
#include "TakePhotoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTakePhotoDlg �Ի���



CTakePhotoDlg::CTakePhotoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAKEPHOTO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTakePhotoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTakePhotoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CameraSw, &CTakePhotoDlg::OnBnClickedCamerasw)
	ON_BN_CLICKED(IDC_Exit, &CTakePhotoDlg::OnBnClickedExit)
END_MESSAGE_MAP()


// CTakePhotoDlg ��Ϣ�������

BOOL CTakePhotoDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	cv::namedWindow("view", cv::WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hParent = ::GetParent(hWnd);//������
	::SetParent(hWnd, GetDlgItem(IDC_TheCamera)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);//����ԭ������
	ShowcameraFlg = false;
	GetDlgItem(IDC_CameraSw)->SetWindowTextW(_T("������ͷ"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTakePhotoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTakePhotoDlg::OnPaint()
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
HCURSOR CTakePhotoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTakePhotoDlg::OnBnClickedCamerasw()
{
	// TODO: Add your control notification handler code here
	CString temp;
	GetDlgItem(IDC_CameraSw)->GetWindowTextW(temp);
	if (temp == "������ͷ")
	{
		ShowcameraFlg = true;
		AfxBeginThread(ShowCamera, this, THREAD_PRIORITY_HIGHEST);
	}
	else
	{
		ShowcameraFlg = false;
	}
	/*CDialogEx::OnOK();*/
}


void CTakePhotoDlg::OnBnClickedExit()
{
	// TODO: Add your control notification handler code here
	CameraFlag = false;
	CDialogEx::OnCancel();
}

UINT CTakePhotoDlg::ShowCamera(void* param)
{
	CTakePhotoDlg* dlg = (CTakePhotoDlg*)param;
	CRect rect;
	CWnd* pWnd = dlg->GetDlgItem(IDC_TheCamera);
	int x = rect.Width();
	int y = rect.Height();
	dlg->GetDlgItem(IDC_CameraSw)->SetWindowTextW(_T("�ر�����ͷ"));
	cv::VideoCapture capture(0);

	while (dlg->ShowcameraFlg)
	{
		cv::Mat frame;
		capture >> frame;
		cv::Mat dst;
		//cv::resize(frame, dst, cv::Size(x, y), 0, 0, 1);//����ͼƬ��С�봰�ڴ�Сһ�£��˾����������߳��е��Բ��ᱨ��
		cv::imshow("view", frame);
		cv::waitKey(30);
	}
	return 0;
}