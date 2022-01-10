#pragma once
#ifndef _DATE_H_
#define _DATE_H_
#include<iostream>
#include<utility>
#include<string>
using namespace std;
class Date {
private:
	int year;
	int month;
	int day;
	int totalDays;//从公元元年1月1日开始的第几天
public:
	Date(int year, int month, int day);
	Date() :year(0), month(0), day(0), totalDays(0) { ; }
	inline int getYear() const { return year; }
	inline int getMonth() const { return month; }
	inline int getDay()const { return day; }
	inline int getMaxDay() const;
	bool isLeapYear() const;
	void show() const;
	int operator-(const Date& date) const {
		return this->totalDays - date.totalDays;
	}
	//重载<
	bool operator< (const Date& date) const {
		if (this->getYear() == date.getYear()) {
			if (this->getMonth() == date.getMonth()) {
				return this->getDay() < date.getDay();
			}
			return this->getMonth() < date.getMonth();
		}
		return this->getYear() < date.getYear();
	}
	//重载输入流
	friend istream& operator >> (istream& in, Date& date);
	//重载输出流
	friend ostream& operator << (ostream& out, Date& date);
	int getCurMonDay() const;
};
#endif // _DATE_H_
