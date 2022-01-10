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
	int totalDays;//�ӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���
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
	//����<
	bool operator< (const Date& date) const {
		if (this->getYear() == date.getYear()) {
			if (this->getMonth() == date.getMonth()) {
				return this->getDay() < date.getDay();
			}
			return this->getMonth() < date.getMonth();
		}
		return this->getYear() < date.getYear();
	}
	//����������
	friend istream& operator >> (istream& in, Date& date);
	//���������
	friend ostream& operator << (ostream& out, Date& date);
	int getCurMonDay() const;
};
#endif // _DATE_H_
