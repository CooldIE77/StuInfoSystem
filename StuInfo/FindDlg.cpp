// FindDlg.cpp: 实现文件
//

#include "pch.h"
#include "StuInfoSystem.h"
#include "afxdialogex.h"
#include "FindDlg.h"


// FindDlg 对话框

IMPLEMENT_DYNAMIC(FindDlg, CDialogEx)

FindDlg::FindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FindDlg, pParent)
	, s_name(_T(""))
{

}

FindDlg::~FindDlg()
{
}

void FindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s_name);
}


BEGIN_MESSAGE_MAP(FindDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &FindDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// FindDlg 消息处理程序


void FindDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);
	if (s_name == TEXT("")) {
		MessageBox(TEXT("您的输入为空！"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}
