#include<iostream>
#include<cmath>
using namespace std;
class SavingAccount {
private:
	int id;//�˺�
	double balance;//���
	double rate;//������
	int lastDate;//�ϴα����������
	double accumulation;//�����ۼ�֮��
	//��¼һ���ʣ�dateΪ���ڣ�amountΪ���
	void record(int date,double amount);
	//��õ�ָ������λ�õĴ������ۼ�ֵ
	inline double acclumulate(int date)const {
		return accumulation + balance * (date - lastDate);
	}
public:
	//���캯��
	SavingAccount(int date, int id, double rate);
	inline int getId() { return id ;}
	inline double getBalance() { return balance; }
	inline double getRate() { return rate; }
	//��ʾ�˻���Ϣ
	inline void show() {
		cout << "#" << id << "\tBalance:" << balance << endl;
	}
	//���
	inline void deposit(int date, double amount);
	//ȡ��
	inline void withdraw(int date, double amount);
	//������Ϣ��һ�����һ��
	inline void settle(int date);
};
SavingAccount::SavingAccount(int date, int id, double rate) 
	:id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	cout << date << "\t#" << id << " is created " << endl;
}
inline void SavingAccount::record(int date, double amount)  {
	//�������䶯ʱ����������ۼ�ֵ
	accumulation = acclumulate(date);
	lastDate = date;//���±䶯����
	amount = floor(amount * 100 + 0.5) / 100;//����2λС��
	balance += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
inline void SavingAccount::settle(int date)  {
	double interest = acclumulate(date) * rate / 365;//��Ϣ
	if (interest!= 0) {
		record(date, interest);
	}
	accumulation = 0;//���¼����ۼ�ֵ
}
inline void SavingAccount::deposit(int date, double amount)  {//���
	record(date, amount);
}
inline void SavingAccount::withdraw(int date, double amount)  {
	if (amount <= balance) {
		record(date, -amount);
	}
	else {
		cout << "�����˻����㣡" << endl;
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