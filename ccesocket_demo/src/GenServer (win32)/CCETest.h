// CCETest.h : main header file for the CCETEST application
//

#if !defined(AFX_CCETEST_H__383BA157_AEF7_4016_ABC6_9EE9CB5517FE__INCLUDED_)
#define AFX_CCETEST_H__383BA157_AEF7_4016_ABC6_9EE9CB5517FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCCETestApp:
// See CCETest.cpp for the implementation of this class
//

class CCCETestApp : public CWinApp
{
public:
	CCCETestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCCETestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCCETestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CCETEST_H__383BA157_AEF7_4016_ABC6_9EE9CB5517FE__INCLUDED_)
