// TakePhoto.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTakePhotoApp: 
// �йش����ʵ�֣������ TakePhoto.cpp
//

class CTakePhotoApp : public CWinApp
{
public:
	CTakePhotoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTakePhotoApp theApp;