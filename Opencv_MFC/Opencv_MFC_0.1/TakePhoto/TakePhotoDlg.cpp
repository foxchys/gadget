
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

	GetDlgItem(IDC_CameraSw)->SetWindowTextW(_T("������ͷ"));
	ShowCaFlg = false;

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


//
//void CTakePhotoDlg::OnBnClickedCamerasw()
//{
//	// TODO: Add your control notification handler code here
//	IplImage *image = NULL; //ԭʼͼ��
//	if (image) cvReleaseImage(&image);
//	image = cvLoadImage("D:\\demo.jpg",1); //��ʾͼƬ
//	/*cv::VideoCapture capture;
//	capture.open(0);
//	cv::Mat frame;
//	capture >> frame;*/
//	//IplImage CamTem;
//	//CamTem = frame;
//	//image = cvCloneImage(&CamTem);
//	DrawPicToHDC(image, IDC_TheCamera);
//	/*DrawPicToHDC(frame, IDC_TheCamera);*/
//}
//
//void CTakePhotoDlg::DrawPicToHDC(IplImage *img, UINT ID)
//{
//	CDC *pDC = GetDlgItem(ID)->GetDC();
//	HDC hDC = pDC->GetSafeHdc();
//	CRect rect;
//	GetDlgItem(ID)->GetClientRect(&rect);
//	CvvImage cimg;
//	cimg.CopyOf(img); // ����ͼƬ
//	cimg.DrawToHDC(hDC, &rect); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
//	ReleaseDC(pDC);
//}



void CTakePhotoDlg::DrawPicToHDC(cv::Mat img, UINT ID)
{
	IplImage *CamShTem;
	IplImage Temp;
	Temp = img;
	CamShTem = cvCloneImage(&Temp);

	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	CvvImage cimg;
	cimg.CopyOf(CamShTem, CamShTem->nChannels); // ����ͼƬ
	cimg.DrawToHDC(hDC, &rect); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	cimg.Destroy();
	ReleaseDC(pDC);
	cvReleaseImage(&CamShTem);
}


void CTakePhotoDlg::OnBnClickedCamerasw()
{
	CString temp;
	GetDlgItem(IDC_CameraSw)->GetWindowTextW(temp);
	if (temp == "������ͷ")
	{
		ShowCaFlg = true;
		AfxBeginThread(ShowCamera, this, THREAD_PRIORITY_HIGHEST);
		GetDlgItem(IDC_CameraSw)->SetWindowTextW(_T("�ر�����ͷ"));
	}
	else
	{
		ShowCaFlg = false;
	}
}

UINT CTakePhotoDlg::ShowCamera(void* param)
{
	CTakePhotoDlg* dlg = (CTakePhotoDlg*)param;

	std::vector<cv::Rect> faces;
	cv::CascadeClassifier face_cascade;
	cv::String face_cascade_name = "haarcascade_frontalface_alt.xml";
	face_cascade.load(face_cascade_name);

	/*CTakePhotoDlg* dlg = (CTakePhotoDlg*)param;*/
	cv::VideoCapture capture;
	capture.open(0);
	cv::Mat frame;
	cv::Mat grayImage;
	while (dlg->ShowCaFlg)
	{
		capture >> frame;
		grayImage.create(frame.size(), frame.type());
		cv::cvtColor(frame, grayImage, CV_BGR2GRAY);
		face_cascade.detectMultiScale(grayImage, faces, 1.1, 3, 0 | CV_HAAR_DO_ROUGH_SEARCH, cv::Size(100, 100));
		for (size_t i = 0; i < faces.size(); i++)
		{
			//cv::Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);//��������Բ��
			//ellipse(frame, center, cv::Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cv::Scalar(0, 255, 0), 4, 8, 0);//��������Բ

			cv::Rect select;//��������  
			select.x = faces[i].x;
			select.y = faces[i].y;
			select.width = faces[i].width;
			select.height = faces[i].height;
			rectangle(frame, select, cv::Scalar(0, 255, 0), 2, 8, 0);//�����������Σ���������ʽvoid rectangle(Mat& img, Rect rec, const Scalar& color, int thickness=1, int lineType=8, int shift=0 )
		}
		dlg->DrawPicToHDC(frame, IDC_TheCamera);
		cv::waitKey(30);
	}
	dlg->GetDlgItem(IDC_CameraSw)->SetWindowTextW(_T("������ͷ"));
	return 0;
}


void CTakePhotoDlg::OnBnClickedExit()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
