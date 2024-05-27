#include "pch.h"
#include "StuInfo.h"

StuInfo::StuInfo(string name, string sex, int class_, double score1, double score2, double score3)
{
	s_name = name;
	s_sex = sex;
	s_class_ = class_;
	s_score1 = score1;
	s_score2=score2;
	s_score3=score3;
	s_sum = score1 + score2 + score3;
}
