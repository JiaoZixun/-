#include"savingsaccount.h"
#include"accumulator.h"
savingsAccount::savingsAccount(Date date, string id, double rate) :Account(date,id), rate(rate),acc(Accumulator(date,0)) {//���û���Ĺ��캯������
	//cout << "#\t" << id << "\t" << "�����˻��������" << endl;
}

void savingsAccount::deposit(Date date, double amount, const string& desc) {//���
	record(date, amount, desc);
	acc.change(date, getBalance());//����������value��Ϊ�˻��н����
}

void savingsAccount::withdraw(Date date, double amount, const string& desc) {
	if (amount <= getBalance()) {
		record(date, -amount, desc);
		acc.change(date, getBalance());
		
	}
	else {
		cout << "�����˻����㣡" << endl;
	}
}

void savingsAccount::settle(Date date) {
	const double interest = acc.getSum(date) * rate / (date - Date(date.getYear() - 1, 1, 1));//��Ϣ
	if (interest != 0 ) {//�����˻�ÿ��һ�½���
		record(date, interest, "��Ϣ");
	}
	acc.reset(date, getBalance());//���¼����ۼ�ֵ
}