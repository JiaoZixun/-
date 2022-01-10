#pragma once
#ifndef _ACCUMULATOR_H_
#define _ACCUMULATOR_H_
#include"date.h"
class Accumulator {
private:
	Date lastDate;
	double value; //账户中的金额数
	double sum;//上一次日期前的按日累加和
public:
	Accumulator(Date date,double value);
	double getSum(Date date) const;
	void change(Date date, double value);
	void reset(Date date, double value);
};
#endif // _ACCUMULATOR_H_
