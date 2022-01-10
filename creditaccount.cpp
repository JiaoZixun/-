#include"creditaccount.h"
//���캯��
creditAccount::creditAccount(Date date, string id, double credit, double rate, double fee) :
	Account(date, id), credit(credit), rate(rate), fee(fee), acc(Accumulator(date, 0)) {
	//cout << "#\t" << id << "\t" << "���ÿ��˻��������" << endl;
}
//�õ��������ö�
double creditAccount::getAvailableCredit() const {
	if (getBalance() < 0) {
		return credit + getBalance();//���ڸ�ծ���������ö��ȥ��ծ
	}
	return credit;
}
//��Ǯû��Ϣ
void creditAccount::deposit(Date date, double amount, const string& desc) {
	record(date, amount, desc);
	acc.change(date, getDebt());
}
//ȡǮ����Ϣ
void creditAccount::withdraw(Date date, double amount, const string& desc) {
	if (amount <= getAvailableCredit()) {
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
	else {
		cout << "����" << endl;
	}
}

void creditAccount::settle(Date date) {
	const double interest = acc.getSum(date) * rate;//��Ϣ
	if (interest != 0) {
		record(date, interest, "��Ϣ");
	}
	//ÿ��һ�������ÿ�����
	if (date.getMonth() == 1 && getAvailableCredit() > fee) {
		record(date, -fee, "����");
	}
	acc.reset(date, getBalance());//���¼����ۼ�ֵ
}
void creditAccount::show() const {
	cout << " " << getId() << "\t" << "Balance��" << getBalance() << "\t" << "��ǰ���ÿ���" << getAvailableCredit() << endl;
}