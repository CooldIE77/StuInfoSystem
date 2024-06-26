﻿#pragma once
#include "afxdialogex.h"


// InfoDlg 对话框

class InfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InfoDlg)

public:
	InfoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~InfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_InfoDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s_name;
	CString s_sex;
	int s_class;
	double s_score1;
	double s_score2;
	double s_score3;
	afx_msg void OnBnClickedOk();
};
