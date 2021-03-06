// CVoipP2PDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CVoipP2PDlg.h"
#include "afxdialogex.h"
#include "CUtil.h"

// CVoipP2PDlg 对话框

IMPLEMENT_DYNAMIC(CVoipP2PDlg, CDialogEx)

CVoipP2PDlg::CVoipP2PDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_VOIP_P2P, pParent)
{
	m_strLocalIP = "";
	m_strAimIP = "";
}

CVoipP2PDlg::~CVoipP2PDlg()
{
}

void CVoipP2PDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS_LOCAL_IP, m_LocalIP);
	DDX_Control(pDX, IDC_IPADDRESS_AIM_IP, m_AimIP);
}


BEGIN_MESSAGE_MAP(CVoipP2PDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CALLING, &CVoipP2PDlg::OnBnClickedButtonCalling)
END_MESSAGE_MAP()


// CVoipP2PDlg 消息处理程序


void CVoipP2PDlg::OnBnClickedButtonCalling()
{
	
}


BOOL CVoipP2PDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_strLocalIP = CUtil::GetLocalIpAddress();
	int pos = m_strLocalIP.find(".");
	string strVal1 = m_strLocalIP.substr(0, pos);
	m_strLocalIP = m_strLocalIP.substr(pos + 1, m_strLocalIP.length() - pos - 1);
	pos = m_strLocalIP.find(".");
	string strVal2 = m_strLocalIP.substr(0, pos);
	m_strLocalIP = m_strLocalIP.substr(pos + 1, m_strLocalIP.length() - pos - 1);
	pos = m_strLocalIP.find(".");
	string strVal3 = m_strLocalIP.substr(0, pos);
	m_strLocalIP = m_strLocalIP.substr(pos + 1, m_strLocalIP.length() - pos - 1);
	string strVal4 = m_strLocalIP;

	int val1 = atoi(strVal1.c_str());
	int val2 = atoi(strVal2.c_str());
	int val3 = atoi(strVal3.c_str());
	int val4 = atoi(strVal4.c_str());
	m_LocalIP.SetAddress(val1, val2, val3, val4);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
