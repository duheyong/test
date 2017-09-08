; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCCETestDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CCETest.h"

ClassCount=3
Class1=CCCETestApp
Class2=CCCETestDlg

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_CCETEST_DIALOG
Class3=CChat
Resource3=IDD_DIALOG1

[CLS:CCCETestApp]
Type=0
HeaderFile=CCETest.h
ImplementationFile=CCETest.cpp
Filter=N

[CLS:CCCETestDlg]
Type=0
HeaderFile=CCETestDlg.h
ImplementationFile=CCETestDlg.cpp
Filter=D
LastObject=IDC_PORT
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_CCETEST_DIALOG]
Type=1
Class=CCCETestDlg
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_RECV,edit,1352728580
Control4=IDC_SEND,edit,1352728580
Control5=IDC_SERVTCP,button,1342308361
Control6=IDC_SERVUDP,button,1342177289
Control7=IDC_STATIC,button,1342177287
Control8=IDC_START,button,1342242816
Control9=IDOK,button,1342242816
Control10=IDC_CLOSE,button,1342242816
Control11=IDC_EXIT,button,1342242816
Control12=IDC_STATIC,static,1342308352
Control13=IDC_PORT,edit,1350631552

[DLG:IDD_DIALOG1]
Type=1
Class=CChat
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_RECV,edit,1350631428
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_SEND,edit,1350631552
Control6=IDC_EXIT,button,1342242816

[CLS:CChat]
Type=0
HeaderFile=Chat.h
ImplementationFile=Chat.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CChat

