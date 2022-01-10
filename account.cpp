#include"account.h"
double Account::total = 0;
RecordMap Account::mp ;
Account::Account(Date date, string id)
	:id(id), balance(0) {
	cout << date << "\t" << "#" << id << " is created " << endl;

}
void Account::record(Date date, double amount, const string &desc) {
	//当余额发生变动时，更新余额累加值
	amount = floor(amount * 100 + 0.5) / 100;//保留2位小数
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
	//存入详情信息结构体作为值
	// date作为键
	Account::mp.emplace(date, Detail(id,date,amount, balance,desc));

}
void Account::error(string msg) const {

		cout << "当前错误信息为：" << msg << endl;
} 
void Account::serach_find(const Date& date1, const Date& date2) {
	auto start = Account::mp.lower_bound(date1);//找到第一个大于等于该日期的详情信息
	auto over = Account::mp.upper_bound(date2);//找到第一个大于该日期的详情信息
	for (; start != over; start++) {
		start->second.show();
	}
}