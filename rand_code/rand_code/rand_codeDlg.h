
// rand_codeDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include<string>
#include<vector>
#include<time.h> 
#include<windows.h>


// Crand_codeDlg dialog
class Crand_codeDlg : public CDialogEx
{
// Construction
public:
	Crand_codeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RAND_CODE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 乱码个数
	int m_number;
	int codenumber;
	// 乱码生成区
	CEdit m_randcode;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	BOOL CopyToClipboard(std::string pszData);
	// 自动生成间隔时间
	int m_times;
	int interval_times;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton5();
};
