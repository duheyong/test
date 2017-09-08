// GenClientDlg.h : header file
//

#if !defined(AFX_GENCLIENTDLG_H__7A63C803_94AB_47F3_BF47_330159539FBD__INCLUDED_)
#define AFX_GENCLIENTDLG_H__7A63C803_94AB_47F3_BF47_330159539FBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClientSocket;

/////////////////////////////////////////////////////////////////////////////
// CGenClientDlg dialog

class CGenClientDlg : public CDialog
{
// Construction
public:
	CGenClientDlg(CWnd* pParent = NULL);	// standard constructor
	~CGenClientDlg();

// Dialog Data
	//{{AFX_DATA(CGenClientDlg)
	enum { IDD = IDD_GENCLIENT_DIALOG };
	CButton	m_btTCP;
	CString	m_sAddress;
	CString	m_sRecv;
	CString	m_sSend;
	CString	m_sPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void Send();
	afx_msg LRESULT OnReceive(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDisconnect(WPARAM wParam, LPARAM lParam);

	HICON m_hIcon;
	CClientSocket *m_ClientSocket;

	// Generated message map functions
	//{{AFX_MSG(CGenClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnExit();
	afx_msg void OnConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENCLIENTDLG_H__7A63C803_94AB_47F3_BF47_330159539FBD__INCLUDED_)
