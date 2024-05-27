#pragma once
#include<vector>
#include"StuInfo.h"
#define SQL_MAX 256
class SQLInterface
{
public:
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL m_sqlCon; //连接数据库
	char sql[SQL_MAX];

	bool Connect_MySQL();
	vector<StuInfo> SQLInterface::GetInfo();
	bool AddInfo(StuInfo Info);  //添加学生信息
	bool DelInfo(StuInfo Info);  //删除学生信息
	bool UpdateInfo(StuInfo old_Info, StuInfo new_Info);  //修改学生信息
	vector<StuInfo> FindInfo(CString name);    //查找信息
	void Close_MySQL();  //关闭数据库
};

