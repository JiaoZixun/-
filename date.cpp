#include"date.h"
#include<cstdlib>//包含exit函数
namespace {//namespace使下面的定义只在当前文件中有效
	//存储平年中某个月1日前有多少天，方便getmaxday函数实现
	const int DAYS_BEFORM_MONTH[] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };
	const int DAYS[]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
};

Date::Date(int year, int month, int day):year(year),month(month),day(day) {
	if (isLeapYear() && month == 2) {
		if (day <= 0 || day > 29) {
			cout << "Invalid date:";
			show();
			cout << endl;
			exit(1);
		}
	}
	if (day <= 0 || day > DAYS[month]) {
		cout << "Invalid date:";
		show();
		cout << endl;
		exit(1);
	}
	totalDays = 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + getMaxDay() + day - 1;//当前日期到元年1月1日的日子数
	//show();
	//cout << "当前距离元年有" << totalDays << endl;
}
int Date::getMaxDay() const {
	if(isLeapYear()&&month>1)
		return DAYS_BEFORM_MONTH[month]+1;
	return DAYS_BEFORM_MONTH[month];
}
int Date::getCurMonDay() const {
	return DAYS[this->month];
}
bool Date::isLeapYear() const {
	if ((!(year % 4) && (year % 100)) || !(year % 400))	return true;//能被4整除但不能被100整除，或者能被400整除
	return false;
}
void Date::show() const {
	cout << year << "-" << month << "-" << day << "\t";
}
istream& operator >> (istream& in, Date& date) {
	char ch;
	in >> date.year ;
	in >> ch;//去掉-
	in >> date.month;
	in >> ch;
	in >> date.day;
	return in;
}
ostream& operator << (ostream& out, Date& date) {
	out << date.year << "-" << date.month << "-" << date.day;
	return out;
}


