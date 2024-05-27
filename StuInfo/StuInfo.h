#pragma once
class StuInfo
{
public:
	string s_name;
	string s_sex;
	int s_class_;
	double s_score1;
	double s_score2;
	double s_score3;
	double s_sum;
	StuInfo() {};
	StuInfo(string name, string sex, int class_, double score1, double score2, double score3);
};

