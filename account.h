#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<iostream>
#include<map>

#include"date.h"
using namespace std;
//����������Ϣ
class Detail {
private:
	string id;
	Date da;
	double v, all;
	string desc;
public:
	Detail(string id,Date da, double v, double all, string desc) :id(id),da(da), v(v), all(all), desc(desc) {

	}
	void show() const{
		cout << "�˺�:" << id << "\t";
		da.show();
		cout << "\t" << v << "\t" << all << "\t" << desc << endl;
	}
};
typedef multimap<Date, Detail> RecordMap;//����洢��Ŀ��¼�Ķ���ӳ��
class Account {
private:
	string id;//�˺�
	double balance;//���
	static double total;//�����˻����ܽ��
	static RecordMap mp;
public:
	//���캯��
	Account(Date date, string id);
	inline string getId() const { return id; }
	inline double getBalance() const { return balance; }
	inline static double getTotal() { return total; }
	void record(Date date, double amount, const string& desc);
	//��ʾ�˻���Ϣ
	virtual void show() const {
		cout << " " << getId() << "\t" << "Balance��" << getBalance() << endl;
	};
	virtual void deposit(Date date, double amount, const string& desc) = 0;
	virtual void withdraw(Date date, double amount, const string& desc) = 0;
	virtual void settle(Date date) = 0;
	void error(string msg) const;
	static void serach_find(const Date &date1, const Date &date2);
};

#endif