#pragma once
#include "CPicControl.h"
#include "CDataShowView.h"
#include "IShowLiveCallback.h"
// CShowLiveDlg 对话框

class CShowLiveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShowLiveDlg)

public:
	CShowLiveDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShowLiveDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHOW_LIVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void addPictureControlListener(CPicControlCallback* pPicControlCallback);
	void addShowLiveListener(IShowLiveCallback* pShowLiveCallback);
	CDataShowView* m_pDataShowView;
	CPicControlCallback* m_pPicControlCallback;
	IShowLiveCallback* m_pShowLiveCallback;
public:
	CPicControl m_Pic1;
	CPicControl m_Pic2;
	CPicControl m_Pic3;
	CPicControl m_Pic4;
	CPicControl m_Pic5;
	CPicControl m_Pic6;
	CPicControl m_Pic7;
	virtual BOOL OnInitDialog();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnClose();
};
