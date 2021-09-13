
// rand_code.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Crand_codeApp:
// See rand_code.cpp for the implementation of this class
//

class Crand_codeApp : public CWinApp
{
public:
	Crand_codeApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Crand_codeApp theApp;