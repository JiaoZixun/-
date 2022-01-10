#pragma once
#ifndef _ACCUMULATOR_H_
#define _ACCUMULATOR_H_
#include"date.h"
class Accumulator {
private:
	Date lastDate;
	double value; //�˻��еĽ����
	double sum;//��һ������ǰ�İ����ۼӺ�
public:
	Accumulator(Date date,double value);
	double getSum(Date date) const;
	void change(Date date, double value);
	void reset(Date date, double value);
};
#endif // _ACCUMULATOR_H_
