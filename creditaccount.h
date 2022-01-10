#pragma once
#ifndef _CREDITACCOUNT_H_
#define _CREDITACCOUNT_H_
#include<iostream>
#include"account.h"
#include"accumulator.h"
#include"date.h"
using namespace std;
class creditAccount :public Account{
private:
	Accumulator acc;
	double credit, rate, fee;
	//��ѯծ��
	double getDebt() const {
		return getBalance() < 0 ? getBalance() : 0;
	}
public:
	creditAccount(Date date, string id, double credit, double rate, double fee);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const;
	void deposit(Date date, double amount, const string &desc);
	void withdraw(Date date, double amount, const string &desc);
	void settle(Date date);//ÿ��1�յ���һ��
	void show() const;
};
#endif // !_CREDITACCOUNT_H_
