// GenClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GenClient.h"
#include "GenClientDlg.h"
#include "ClientSocket.h"
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGenClientDlg dialog

CGenClientDlg::CGenClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGenClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGenClientDlg)
	m_sAddress = _T("");
	m_sRecv = _T("");
	m_sSend = _T("");
	m_sPort = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_ClientSocket = NULL;
}

CGenClientDlg::~CGenClientDlg()
{
	if(m_ClientSocket)
		delete m_ClientSocket;

	CDialog::~CDialog();
}

void CGenClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGenClientDlg)
	DDX_Control(pDX, IDC_TCP, m_btTCP);
	DDX_Text(pDX, IDC_ADDRESS, m_sAddress);
	DDX_Text(pDX, IDC_NETRECV, m_sRecv);
	DDX_Text(pDX, IDC_NETSEND, m_sSend);
	DDX_Text(pDX, IDC_PORT, m_sPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGenClientDlg, CDialog)
	//{{AFX_MSG_MAP(CGenClientDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, OnExit)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_MESSAGE(SOCK_ONRECEIVE, OnReceive)
	ON_MESSAGE(SOCK_ONCLOSE, OnDisconnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGenClientDlg message handlers

BOOL CGenClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_ClientSocket = new CClientSocket(this);
	m_ClientSocket->SetEolFormat(CCESocket::EOL_CR);
	m_btTCP.SetCheck(1);
	m_sAddress = "127.0.0.1";
	m_sPort = "5559";
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGenClientDlg::Send()
{
	UpdateData();
	m_ClientSocket->SendLine(m_sSend);
}

LRESULT CGenClientDlg::OnReceive(WPARAM wParam, LPARAM lParam)
{
	CString str, temp;

	while(m_ClientSocket->GetDataSize() > 0 && m_ClientSocket->ReadString(temp))
		str += " "+temp;

	GetDlgItem(IDC_NETRECV)->SetWindowText(str);

	return 0;
}

LRESULT CGenClientDlg::OnDisconnect(WPARAM wParam, LPARAM lParam)
{
	GetDlgItem(IDC_NETRECV)->SetWindowText("Disconnected!");
	GetDlgItem(IDC_CONNECT)->SetWindowText("Connect");
	return 0;
}

void CGenClientDlg::OnPaint() 
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
HCURSOR CGenClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGenClientDlg::OnOK() 
{
	if(m_ClientSocket->GetSocketState() > CCESocket::CREATED)
		Send();
}

void CGenClientDlg::OnExit() 
{
	CDialog::OnOK();	
}

void CGenClientDlg::OnConnect() 
{
	int sockType;
	UINT port;

	//If it's already connected: disconnect.
	if(m_ClientSocket->GetSocketState() > CCESocket::CREATED)
	{
		m_ClientSocket->Disconnect();
		GetDlgItem(IDC_CONNECT)->SetWindowText("Connect");
		return;
	}

	UpdateData();

	if(m_btTCP.GetCheck() == 1)
		sockType = SOCK_STREAM;
	else
		sockType = SOCK_DGRAM;

	port = atoi(m_sPort);

	if(m_ClientSocket->Create(sockType))
		if(m_ClientSocket->Connect(m_sAddress, port))
		{
			GetDlgItem(IDC_CONNECT)->SetWindowText("Disconnect");
			return;
		}
		
	m_ClientSocket->Disconnect();
}
