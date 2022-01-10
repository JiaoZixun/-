#include<iostream>
#include<cmath>
using namespace std;
class SavingAccount {
private:
	int id;//账号
	double balance;//余额
	double rate;//年利率
	int lastDate;//上次变更余额的日期
	double accumulation;//余额按日累加之和
	//记录一笔帐，date为日期，amount为金额
	void record(int date,double amount);
	//获得到指定日期位置的存款金额按日累加值
	inline double acclumulate(int date)const {
		return accumulation + balance * (date - lastDate);
	}
public:
	//构造函数
	SavingAccount(int date, int id, double rate);
	inline int getId() { return id ;}
	inline double getBalance() { return balance; }
	inline double getRate() { return rate; }
	//显示账户信息
	inline void show() {
		cout << "#" << id << "\tBalance:" << balance << endl;
	}
	//存款
	inline void deposit(int date, double amount);
	//取款
	inline void withdraw(int date, double amount);
	//结算利息，一年调用一次
	inline void settle(int date);
};
SavingAccount::SavingAccount(int date, int id, double rate) 
	:id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	cout << date << "\t#" << id << " is created " << endl;
}
inline void SavingAccount::record(int date, double amount)  {
	//当余额发生变动时，更新余额累加值
	accumulation = acclumulate(date);
	lastDate = date;//更新变动日期
	amount = floor(amount * 100 + 0.5) / 100;//保留2位小数
	balance += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
inline void SavingAccount::settle(int date)  {
	double interest = acclumulate(date) * rate / 365;//年息
	if (interest!= 0) {
		record(date, interest);
	}
	accumulation = 0;//从新计算累加值
}
inline void SavingAccount::deposit(int date, double amount)  {//存款
	record(date, amount);
}
inline void SavingAccount::withdraw(int date, double amount)  {
	if (amount <= balance) {
		record(date, -amount);
	}
	else {
		cout << "您的账户余额不足！" << endl;
	}
}

int main1() {
	SavingAccount sa0(1, 21000101, 0.015);
	SavingAccount sa1(2, 21000102, 0.015);

	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);
	
	
	sa0.settle(90);
	sa1.settle(90);

	sa0.show();
	sa1.show();


	return 0;
}