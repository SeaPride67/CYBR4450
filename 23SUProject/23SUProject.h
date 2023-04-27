
// 23SUProject.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C23SUProjectApp:
// See 23SUProject.cpp for the implementation of this class
//

class C23SUProjectApp : public CWinApp
{
public:
	C23SUProjectApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C23SUProjectApp theApp;
