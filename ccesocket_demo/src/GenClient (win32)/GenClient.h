// GenClient.h : main header file for the GENCLIENT application
//

#if !defined(AFX_GENCLIENT_H__DA6A5D59_8622_42B5_9EC7_1AD2D4630172__INCLUDED_)
#define AFX_GENCLIENT_H__DA6A5D59_8622_42B5_9EC7_1AD2D4630172__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGenClientApp:
// See GenClient.cpp for the implementation of this class
//

class CGenClientApp : public CWinApp
{
public:
	CGenClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGenClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENCLIENT_H__DA6A5D59_8622_42B5_9EC7_1AD2D4630172__INCLUDED_)
