// CCETestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CCETest.h"
#include "CCETestDlg.h"
#include "MySocket.h"
#include "Chat.h"
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCCETestDlg dialog

CCCETestDlg::CCCETestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCCETestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCCETestDlg)
	m_sRecv = _T("");
	m_sSend = _T("");
	m_sPort = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCCETestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCCETestDlg)
	DDX_Control(pDX, IDC_SERVTCP, m_bServerType);
	DDX_Text(pDX, IDC_RECV, m_sRecv);
	DDX_Text(pDX, IDC_SEND, m_sSend);
	DDX_Text(pDX, IDC_PORT, m_sPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCCETestDlg, CDialog)
	//{{AFX_MSG_MAP(CCCETestDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStartServer)
	ON_BN_CLICKED(IDC_CLOSE, OnCloseServer)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_MESSAGE(ON_RECEIVE, OnReceiveData)
	ON_MESSAGE(ON_CLOSE, OnDisconnected)
	ON_MESSAGE(ON_ACCEPT, OnAccept)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCCETestDlg message handlers

BOOL CCCETestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_server = new CMySocket(this);
	m_bServerType.SetCheck(1);
	m_sPort = _T("3000");
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCCETestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCCETestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

LRESULT CCCETestDlg::OnAccept(WPARAM wParam, LPARAM lParam)
{
	CChat *chatDlg;
	
	chatDlg = new CChat;
	chatDlg->ConnectTo((SOCKET) wParam);
	chatDlg->Create(IDD_DIALOG1);

	return 0;
}

LRESULT CCCETestDlg::OnReceiveData(WPARAM wParam, LPARAM lParam)
{
	while(m_server->GetDataSize() > 0 && m_server->ReadString(m_sRecv))
		UpdateData(FALSE);
	return 0;
}

LRESULT CCCETestDlg::OnDisconnected(WPARAM wParam, LPARAM lParam)
{
	if(m_server->GetSocketType() == SOCK_DGRAM)
	{
		m_sRecv = "Remote host disconnected";
		UpdateData(FALSE);
		return 0;
	}
	GetDlgItem(IDC_START)->EnableWindow(TRUE);
	return 0;
}

void CCCETestDlg::OnStartServer() 
{
	bool created;
	UpdateData();

	if(m_bServerType.GetCheck())
		created = m_server->Create(SOCK_STREAM);
	else
		created = m_server->Create(SOCK_DGRAM);

	if(created)
		if(m_server->Accept(atoi(m_sPort)))
			GetDlgItem(IDC_START)->EnableWindow(FALSE);
}

void CCCETestDlg::OnCloseServer() 
{
	m_server->Disconnect();
	GetDlgItem(IDC_START)->EnableWindow(TRUE);
}

void CCCETestDlg::OnOK() 
{
	int len;
	UpdateData();
	m_sSend += "\r\n";
	len = m_sSend.GetLength();
	m_server->Send(m_sSend, len);
}

void CCCETestDlg::OnExit() 
{
	PostQuitMessage(0);	
}
