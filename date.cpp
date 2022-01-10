#include"date.h"
#include<cstdlib>//����exit����
namespace {//namespaceʹ����Ķ���ֻ�ڵ�ǰ�ļ�����Ч
	//�洢ƽ����ĳ����1��ǰ�ж����죬����getmaxday����ʵ��
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
	totalDays = 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + getMaxDay() + day - 1;//��ǰ���ڵ�Ԫ��1��1�յ�������
	//show();
	//cout << "��ǰ����Ԫ����" << totalDays << endl;
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
	if ((!(year % 4) && (year % 100)) || !(year % 400))	return true;//�ܱ�4���������ܱ�100�����������ܱ�400����
	return false;
}
void Date::show() const {
	cout << year << "-" << month << "-" << day << "\t";
}
istream& operator >> (istream& in, Date& date) {
	char ch;
	in >> date.year ;
	in >> ch;//ȥ��-
	in >> date.month;
	in >> ch;
	in >> date.day;
	return in;
}
ostream& operator << (ostream& out, Date& date) {
	out << date.year << "-" << date.month << "-" << date.day;
	return out;
}


