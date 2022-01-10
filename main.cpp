#include"account.h"
#include"savingsaccount.h"
#include"accumulator.h"
#include"date.h"
#include"creditaccount.h"
#include<vector>
#include<fstream>
using namespace std;
int main() {
    ofstream fout("data.txt");//д��

    Date date(2008, 11, 1);//��ʼʱ��ڵ㣬ÿ��ʱ�������Ҫ���£�Ӧ���ȴӱ����ļ��ж�ȡʱ��ڵ�
    vector<Account*> accounts;
    Account* acc;
    std::cout << "������(a)�����û���(d)��(w)ȡ�(s)��ѯ�˻���Ϣ��(c)�����(n)�����¸��£�(q)��ѯ�����������м�¼��(e)�˳�" << endl;

    while (1) {
        std::cout << date << "\t Total��" << Account::getTotal() << "\t command> ";
        char str;
        cin >> str;
        if (str == 'a') {//�����û�
            char type;
            string id;
            cin >> type >> id;//�˻����ͣ�s��ʾ�����˻���c��ʾ���ÿ��˻�
            if (type == 's') {
                double rate;
                cin >> rate;
                acc = new savingsAccount(date, id, rate);
                fout << str << " " << type << " " << id << " " << rate << endl;
                //cout << str << " " << id << " " << type << " " << rate << endl;
            }
            else {
                double credit, fee,rate;
                cin >> credit >> rate >> fee;
                acc = new creditAccount(date, id, credit, rate, fee);
                fout << str << " " << type << " " << id << " " << credit << " " << rate << " " << fee << endl;
            }
            accounts.push_back(acc);
        }
        else if (str == 'd') {//�������˻�id�������
            int idx;
            double amount;
            string desc;
            cin >> idx >> amount;
            std::getline(cin, desc);//��ȡһ��
            if (idx >= 0 && idx < accounts.size()) {//�����±�Ϸ���
                accounts[idx]->deposit(date, amount, desc);
            }
            else {
                std::cout << "û���ҵ����˻���������" << endl;
            }
            fout << str << " " << idx << " " << amount << " " << desc << endl;
        }
        else if (str == 'w') {//ȡǮ������id��ȡ����
            int idx;
            double amount;
            string desc;
            cin >> idx >> amount;
            std::getline(cin, desc);
            if (idx >= 0 && idx < accounts.size()) {//�����±�Ϸ���
                accounts[idx]->withdraw(date, amount, desc);
            }
            else {
                std::cout << "û���ҵ����˻���������" << endl;
            }
            fout << str << " " << idx << " " << amount << " " << desc << endl;
        }
        else if (str == 's') {//��ѯ�����˻���Ϣ
            for (int i = 0; i < accounts.size(); i++) {
                std::cout << "[" << i << "]" << "\t";
                accounts[i]->show();
            }
        }
        else if (str == 'c') {//�ı����ڣ����������ڼ��죬���ܻ��˲��ܳ�������������ڣ�����ʱ��ڵ�
            int day;
            cin >> day;
            if (day < date.getDay()) {
                std::cout << "��������֮ǰ������" << endl;
            }
            else if(day>date.getCurMonDay()){
                std::cout << "�������볬���·ݵ�����" << endl;
            }
            else {
                date = Date(date.getYear(), date.getMonth(), day);
            }
            fout << str << " " << day << endl;
        }
        else if (str == 'n') {//������һ���£���ǰΪ12ʱ��������һ�꣬ÿ��һ��һ�ż��㴢���˻���Ϣ������ʱ��ڵ�
            if (date.getMonth() == 12) {
                date = Date(date.getYear() + 1, 1, 1);//��������1��1��

            }
            else {
                date = Date(date.getYear(), date.getMonth() + 1, 1);//�����¸���1��
            }
            for (auto it = accounts.begin(); it != accounts.end(); it++)   (*it)->settle(date);//���ÿ��˻�ÿ�½��㣬�����˻�ÿ�����
            fout << str << endl;
        }
        else if (str == 'q') {//��ѯ��Χ��������Ϣ
            Date date1, date2;
            cin >> date1 >> date2;
       
            if (date2 < date1) {
                std::cout << "�ڶ������ڱ�����ڵ�һ�����ڣ�����������" << endl;
            }
            else if (date1.getMonth() <= 0 || date1.getMonth() > 12 || date2.getMonth() <= 0 || date2.getMonth() > 12) {
                std::cout << "������Ϸ�����" << endl;
            }
            else if (date1.getDay() > date1.getCurMonDay() || date2.getDay() > date2.getCurMonDay()) {
                std::cout << "������Ϸ�����" << endl;
            }
            else {
                Account::serach_find(date1, date2);//������������(xxxx-xx-xx)�м�ո����
            }
            fout << str << " " << date1 << " " << date2 << endl;
        }
        else if (str == 'e') {//�˳�����
            break;
        }
    }
    fout.close();
    std::cout << "����ʱʱ��Ϊ��";
    std::cout << date << endl;
    std::cout << "Total: " << Account::getTotal() << endl;
    return 0;
}