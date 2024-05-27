// InfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "StuInfoSystem.h"
#include "afxdialogex.h"
#include "InfoDlg.h"


// InfoDlg 对话框

IMPLEMENT_DYNAMIC(InfoDlg, CDialogEx)

InfoDlg::InfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_InfoDlg, pParent)
	, s_name(_T(""))
	, s_sex(_T(""))
	, s_class(1)
	, s_score1(60)
	, s_score2(60)
	, s_score3(60)
{

}

InfoDlg::~InfoDlg()
{
}

void InfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s_name);
	DDX_Text(pDX, IDC_EDIT2, s_sex);
	DDX_Text(pDX, IDC_EDIT3, s_class);
	DDX_Text(pDX, IDC_EDIT4, s_score1);
	DDX_Text(pDX, IDC_EDIT5, s_score2);
	DDX_Text(pDX, IDC_EDIT6, s_score3);
}


BEGIN_MESSAGE_MAP(InfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &InfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// InfoDlg 消息处理程序


void InfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);   //更新每个编辑框的数据
	if (s_name == TEXT("") || s_sex == TEXT("")) {
		MessageBox(TEXT("您有输入为空！"), TEXT("提示"));
		return;
	}
	if (s_score1 < 0 || s_score1>100 || s_score2 < 0 || s_score2>100 || s_score3 < 0 || s_score3>100) {
		MessageBox(TEXT("您输入的成绩有误！"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}
