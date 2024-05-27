#pragma once
#include "afxdialogex.h"


// FindDlg 对话框

class FindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FindDlg)

public:
	FindDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FindDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FindDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s_name;
	afx_msg void OnBnClickedOk();
};
