// TakePhotoDlg.h : ͷ�ļ�
//

#pragma once

//////opencvͷ�ļ�//////////////// 

//#include "opencv\cv.h"
//#include "opencv\highgui.h"


#include"CvvImage.h"//���mfc��ʾͼ�����
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
/////////////////////////////////
//#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <ctime>//Windowsϵͳ�������

// CTakePhotoDlg �Ի���
class CTakePhotoDlg : public CDialogEx
{
// ����
public:
	CTakePhotoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAKEPHOTO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//void DrawPicToHDC(IplImage *img, UINT ID);//����ͷ��ʾ������
	void DrawPicToHDC(cv::Mat img, UINT ID);//����ͷ��ʾ������
	afx_msg void OnBnClickedCamerasw();
	afx_msg void OnBnClickedExit();
	static UINT ShowCamera(void* param);
	bool ShowCaFlg;
};
