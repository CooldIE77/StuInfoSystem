
// StuInfoSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "StuInfoSystem.h"
#include "StuInfoSystemDlg.h"
#include "afxdialogex.h"
#include "InfoDlg.h"
#include"FindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStuInfoSystemDlg 对话框



CStuInfoSystemDlg::CStuInfoSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUINFOSYSTEM_DIALOG, pParent)
	, s_max(0)
	, s_min(0)
	, s_avg(_T(""))
	, s_pass(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStuInfoSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, s_class);
	DDX_Control(pDX, IDC_COMBO2, s_subject);
	//  DDX_Text(pDX, IDC_EDIT1, s_avg);
	DDX_Text(pDX, IDC_EDIT2, s_max);
	DDX_Text(pDX, IDC_EDIT3, s_min);
	//  DDX_Text(pDX, IDC_EDIT4, s_pass);
	DDX_Text(pDX, IDC_EDIT1, s_avg);
	DDX_Text(pDX, IDC_EDIT4, s_pass);
	DDX_Control(pDX, IDC_COMBO3, s_select);
}

BEGIN_MESSAGE_MAP(CStuInfoSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CStuInfoSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStuInfoSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CStuInfoSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CStuInfoSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CStuInfoSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CStuInfoSystemDlg::OnBnClickedButton7)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CStuInfoSystemDlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON5, &CStuInfoSystemDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CStuInfoSystemDlg 消息处理程序

BOOL CStuInfoSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("性别"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, _T("班级"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, _T("语文"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, _T("数学"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(5, _T("英语"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(6, _T("总分"), LVCFMT_LEFT, 100);


	s_class.AddString(TEXT("1班"));
	s_class.AddString(TEXT("2班"));
	s_class.AddString(TEXT("3班"));
	s_class.AddString(TEXT("4班"));
	s_class.AddString(TEXT("全部"));
	s_class.SetCurSel(4);  //默认选择

	s_subject.AddString(TEXT("语文"));
	s_subject.AddString(TEXT("数学"));
	s_subject.AddString(TEXT("英语"));
	s_subject.SetCurSel(0);

	
	s_select.AddString(TEXT("总分"));
	s_select.AddString(TEXT("班级"));
	s_select.AddString(TEXT("语文"));
	s_select.AddString(TEXT("数学"));
	s_select.AddString(TEXT("英语"));

	s_select.SetCurSel(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStuInfoSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStuInfoSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStuInfoSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStuInfoSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (SQL.Connect_MySQL()) {
		Info = SQL.GetInfo();
		UpdateList();
	}
	else {
		return;
	}

}

void CStuInfoSystemDlg::UpdateList()
{
	m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < Info.size(); i++) {
		m_list.InsertItem(i, Info[i].s_name.c_str());
		m_list.SetItemText(i, 1, Info[i].s_sex.c_str());
		str.Format(TEXT("%d"), Info[i].s_class_);
		m_list.SetItemText(i, 2, str);
		str.Format(TEXT("%.1lf"), Info[i].s_score1);
		m_list.SetItemText(i, 3, str);
		str.Format(TEXT("%.1lf"), Info[i].s_score2);
		m_list.SetItemText(i, 4, str);
		str.Format(TEXT("%.1lf"), Info[i].s_score3);
		m_list.SetItemText(i, 5, str);
		str.Format(TEXT("%.1lf"), Info[i].s_sum);
		m_list.SetItemText(i, 6, str);
	}

}


void CStuInfoSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	InfoDlg dlg;
	if (dlg.DoModal() == IDOK) {//弹出对话框,点击确定后执行下面步骤
		//AddInfo是将数据添加到数据库中
		if (SQL.AddInfo(StuInfo(dlg.s_name.GetBuffer(), dlg.s_sex.GetBuffer()
			, dlg.s_class, dlg.s_score1, dlg.s_score2, dlg.s_score3))) {
			MessageBox(TEXT("添加成功！"), TEXT("提示"));
			// 将添加的数据显示到列表中
			Info.push_back(StuInfo(dlg.s_name.GetBuffer(), dlg.s_sex.GetBuffer()
				, dlg.s_class, dlg.s_score1, dlg.s_score2, dlg.s_score3));
			UpdateList();
		}
	}

}


void CStuInfoSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();   //获取选中的行号
	if (nIndex == -1) {
		MessageBox(TEXT("请先选择要删除的数据！"), TEXT("提示"));
		return;
	}
	else {
		UINT i;
		i = MessageBox(_T("确认删除这条信息吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES) {
			if (SQL.DelInfo(Info[nIndex])) {
				MessageBox(TEXT("删除成功!"), TEXT("提示"));
				Info.erase(Info.begin() + nIndex);
				UpdateList();
			}
		}
	}

}


void CStuInfoSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();   //获取选中的行号
	if (nIndex == -1) {
		MessageBox(TEXT("请先选择要修改的数据！"), TEXT("提示"));
		return;
	}
	else {
		InfoDlg dlg;
		dlg.s_name = Info[nIndex].s_name.c_str();
		dlg.s_sex = Info[nIndex].s_sex.c_str();
		dlg.s_class = Info[nIndex].s_class_;
		dlg.s_score1 = Info[nIndex].s_score1;
		dlg.s_score2 = Info[nIndex].s_score2;
		dlg.s_score3 = Info[nIndex].s_score3;
		if (dlg.DoModal() == IDOK) {
			if (SQL.UpdateInfo(Info[nIndex], StuInfo(dlg.s_name.GetBuffer(), dlg.s_sex.GetBuffer()
				, dlg.s_class, dlg.s_score1, dlg.s_score2, dlg.s_score3))) {
				MessageBox(TEXT("修改成功!"), TEXT("提示"));
				Info[nIndex] = StuInfo(dlg.s_name.GetBuffer(), dlg.s_sex.GetBuffer()
					, dlg.s_class, dlg.s_score1, dlg.s_score2, dlg.s_score3);
				UpdateList();
			}
		}
		
	}
}


void CStuInfoSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	FindDlg dlg;
	if (dlg.DoModal() == IDOK) {
		vector<StuInfo> result = SQL.FindInfo(dlg.s_name);
		if (result.empty()) {
			MessageBox(TEXT("查无此人!"), TEXT("提示"));
			return;
		}
		//清空列表，遍历result
		m_list.DeleteAllItems();
		CString str;
		for (int i = 0; i < result.size(); i++) {
			m_list.InsertItem(i, result[i].s_name.c_str());
			m_list.SetItemText(i, 1, result[i].s_sex.c_str());
			str.Format(TEXT("%d"), result[i].s_class_);
			m_list.SetItemText(i, 2, str);
			str.Format(TEXT("%.1lf"), result[i].s_score1);
			m_list.SetItemText(i, 3, str);
			str.Format(TEXT("%.1lf"), result[i].s_score2);
			m_list.SetItemText(i, 4, str);
			str.Format(TEXT("%.1lf"), result[i].s_score3);
			m_list.SetItemText(i, 5, str);
		}
	}
}


void CStuInfoSystemDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码


	int num = 0;
	double sum = 0;
	double max = 0;
	double min = 100;
	int pass = 0;

	int cur_class = s_class.GetCurSel();  //获取选中班级
	int cur_subject = s_subject.GetCurSel();

	vector<double> select_score;
	for (int i = 0; i < Info.size(); i++) {
		if (Info[i].s_class_ == cur_class + 1 || cur_class == 4) {
			//判断科目
			switch (cur_subject)
			{
			case 0:
				select_score.push_back(Info[i].s_score1);
				break;
			case 1:
				select_score.push_back(Info[i].s_score2);
				break;
			case 2:
				select_score.push_back(Info[i].s_score3);
				break;
			default:
				break;
			}
		}
	}

	for (int i = 0; i < select_score.size(); i++) {
		sum += select_score[i];
		max = max(max, select_score[i]);
		min = min(min, select_score[i]);
		if (select_score[i] >= 60) pass++;
	}
	num = select_score.size();

	s_avg.Format(TEXT("%.2lf"), sum / num);
	s_pass.Format(TEXT("%.2lf"), pass*1.0 / num);
	s_max = max;
	s_min = min;

	UpdateData(false);
}

bool cmp_sum(StuInfo a, StuInfo b) {
	return a.s_sum > b.s_sum;
}
bool cmp_class(StuInfo a, StuInfo b) {
	return a.s_class_ < b.s_class_;
}

bool cmp_score1(StuInfo a, StuInfo b) {
	return a.s_score1 > b.s_score1;
}

bool cmp_score2(StuInfo a, StuInfo b) {
	return a.s_score2 > b.s_score2;
}

bool cmp_score3(StuInfo a, StuInfo b) {
	return a.s_score3 > b.s_score3;
}

//当选择下拉框后触发事件
void CStuInfoSystemDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	int cur_select = s_select.GetCurSel();
	//if (cur_select == 0) sort(Info.begin(), Info.end(), cmp);
	switch (cur_select)
	{
	case 0:
		sort(Info.begin(), Info.end(), cmp_sum);
		break;
	case 1:
		sort(Info.begin(), Info.end(), cmp_class);
		break;
	case 2:
		sort(Info.begin(), Info.end(), cmp_score1);
		break;
	case 3:
		sort(Info.begin(), Info.end(), cmp_score2);
		break;
	case 4:
		sort(Info.begin(), Info.end(), cmp_score3);
		break;
	default:
		break;
	}
	UpdateList();
}


void CStuInfoSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确认要退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES) {
		//关闭数据库
		SQL.Close_MySQL();
		exit(0);
	}
}
