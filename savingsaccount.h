#pragma once
#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_
#include<iostream>
#include"date.h"
#include"account.h"
#include"accumulator.h"
using namespace std;
class savingsAccount :public Account {
private:
	Accumulator acc;
	double rate;
public:
	savingsAccount(Date date, string id, double rate);
	double getRate() const { return rate; }
	void deposit(Date date, double amount, const string &desc);
	void withdraw(Date date, double amount, const string &desc);
	void settle(Date date);
};
#endif // !_SAVINGSACCOUNT_H_
