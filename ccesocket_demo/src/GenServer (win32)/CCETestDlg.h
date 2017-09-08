// CCETestDlg.h : header file
//

#if !defined(AFX_CCETESTDLG_H__784344AB_6757_4970_AA6F_78FFB2651889__INCLUDED_)
#define AFX_CCETESTDLG_H__784344AB_6757_4970_AA6F_78FFB2651889__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMySocket;

/////////////////////////////////////////////////////////////////////////////
// CCCETestDlg dialog

class CCCETestDlg : public CDialog
{
// Construction
public:
	CCCETestDlg(CWnd* pParent = NULL);	// standard constructor

	afx_msg LRESULT OnAccept(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnReceiveData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDisconnected(WPARAM wParam, LPARAM lParam);

// Dialog Data
	//{{AFX_DATA(CCCETestDlg)
	enum { IDD = IDD_CCETEST_DIALOG };
	CButton	m_bServerType;
	CString	m_sRecv;
	CString	m_sSend;
	CString	m_sPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCCETestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMySocket *m_server;

	// Generated message map functions
	//{{AFX_MSG(CCCETestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartServer();
	afx_msg void OnCloseServer();
	virtual void OnOK();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CCETESTDLG_H__784344AB_6757_4970_AA6F_78FFB2651889__INCLUDED_)
