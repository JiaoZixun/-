#include"account.h"
double Account::total = 0;
RecordMap Account::mp ;
Account::Account(Date date, string id)
	:id(id), balance(0) {
	cout << date << "\t" << "#" << id << " is created " << endl;

}
void Account::record(Date date, double amount, const string &desc) {
	//�������䶯ʱ����������ۼ�ֵ
	amount = floor(amount * 100 + 0.5) / 100;//����2λС��
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
	//����������Ϣ�ṹ����Ϊֵ
	// date��Ϊ��
	Account::mp.emplace(date, Detail(id,date,amount, balance,desc));

}
void Account::error(string msg) const {

		cout << "��ǰ������ϢΪ��" << msg << endl;
} 
void Account::serach_find(const Date& date1, const Date& date2) {
	auto start = Account::mp.lower_bound(date1);//�ҵ���һ�����ڵ��ڸ����ڵ�������Ϣ
	auto over = Account::mp.upper_bound(date2);//�ҵ���һ�����ڸ����ڵ�������Ϣ
	for (; start != over; start++) {
		start->second.show();
	}
}