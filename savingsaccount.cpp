#include"savingsaccount.h"
#include"accumulator.h"
savingsAccount::savingsAccount(Date date, string id, double rate) :Account(date,id), rate(rate),acc(Accumulator(date,0)) {//调用基类的构造函数构造
	//cout << "#\t" << id << "\t" << "储蓄账户创建完成" << endl;
}

void savingsAccount::deposit(Date date, double amount, const string& desc) {//存款
	record(date, amount, desc);
	acc.change(date, getBalance());//将工具类中value改为账户中金额数
}

void savingsAccount::withdraw(Date date, double amount, const string& desc) {
	if (amount <= getBalance()) {
		record(date, -amount, desc);
		acc.change(date, getBalance());
		
	}
	else {
		cout << "您的账户余额不足！" << endl;
	}
}

void savingsAccount::settle(Date date) {
	const double interest = acc.getSum(date) * rate / (date - Date(date.getYear() - 1, 1, 1));//年息
	if (interest != 0 ) {//储蓄账户每年一月结算
		record(date, interest, "利息");
	}
	acc.reset(date, getBalance());//从新计算累加值
}