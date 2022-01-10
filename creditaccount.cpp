#include"creditaccount.h"
//构造函数
creditAccount::creditAccount(Date date, string id, double credit, double rate, double fee) :
	Account(date, id), credit(credit), rate(rate), fee(fee), acc(Accumulator(date, 0)) {
	//cout << "#\t" << id << "\t" << "信用卡账户创建完成" << endl;
}
//得到可用信用额
double creditAccount::getAvailableCredit() const {
	if (getBalance() < 0) {
		return credit + getBalance();//存在负债，返回信用额减去负债
	}
	return credit;
}
//存钱没利息
void creditAccount::deposit(Date date, double amount, const string& desc) {
	record(date, amount, desc);
	acc.change(date, getDebt());
}
//取钱有利息
void creditAccount::withdraw(Date date, double amount, const string& desc) {
	if (amount <= getAvailableCredit()) {
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
	else {
		cout << "余额不足" << endl;
	}
}

void creditAccount::settle(Date date) {
	const double interest = acc.getSum(date) * rate;//月息
	if (interest != 0) {
		record(date, interest, "利息");
	}
	//每年一月收信用卡卡费
	if (date.getMonth() == 1 && getAvailableCredit() > fee) {
		record(date, -fee, "卡费");
	}
	acc.reset(date, getBalance());//从新计算累加值
}
void creditAccount::show() const {
	cout << " " << getId() << "\t" << "Balance：" << getBalance() << "\t" << "当前信用卡余额：" << getAvailableCredit() << endl;
}