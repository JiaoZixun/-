#include"account.h"
#include"savingsaccount.h"
#include"accumulator.h"
#include"date.h"
#include"creditaccount.h"
#include<vector>
#include<fstream>
using namespace std;
int main() {
    ofstream fout("data.txt");//写入

    Date date(2008, 11, 1);//初始时间节点，每次时间更改需要更新，应该先从备份文件中读取时间节点
    vector<Account*> accounts;
    Account* acc;
    std::cout << "操作：(a)增加用户，(d)存款，(w)取款，(s)查询账户信息，(c)快进，(n)进入下个月，(q)查询日期区间所有记录，(e)退出" << endl;

    while (1) {
        std::cout << date << "\t Total：" << Account::getTotal() << "\t command> ";
        char str;
        cin >> str;
        if (str == 'a') {//增加用户
            char type;
            string id;
            cin >> type >> id;//账户类型，s表示储蓄账户，c表示信用卡账户
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
        else if (str == 'd') {//存款：读入账户id，存款金额
            int idx;
            double amount;
            string desc;
            cin >> idx >> amount;
            std::getline(cin, desc);//读取一行
            if (idx >= 0 && idx < accounts.size()) {//检验下标合法性
                accounts[idx]->deposit(date, amount, desc);
            }
            else {
                std::cout << "没有找到该账户，请重试" << endl;
            }
            fout << str << " " << idx << " " << amount << " " << desc << endl;
        }
        else if (str == 'w') {//取钱，读入id，取款金额
            int idx;
            double amount;
            string desc;
            cin >> idx >> amount;
            std::getline(cin, desc);
            if (idx >= 0 && idx < accounts.size()) {//检验下标合法性
                accounts[idx]->withdraw(date, amount, desc);
            }
            else {
                std::cout << "没有找到该账户，请重试" << endl;
            }
            fout << str << " " << idx << " " << amount << " " << desc << endl;
        }
        else if (str == 's') {//查询所有账户信息
            for (int i = 0; i < accounts.size(); i++) {
                std::cout << "[" << i << "]" << "\t";
                accounts[i]->show();
            }
        }
        else if (str == 'c') {//改变日期，读入快进到第几天，不能回退不能超过本月最大日期，更改时间节点
            int day;
            cin >> day;
            if (day < date.getDay()) {
                std::cout << "不能输入之前的日期" << endl;
            }
            else if(day>date.getCurMonDay()){
                std::cout << "不能输入超过月份的日子" << endl;
            }
            else {
                date = Date(date.getYear(), date.getMonth(), day);
            }
            fout << str << " " << day << endl;
        }
        else if (str == 'n') {//进入下一个月，当前为12时，进入下一年，每年一月一号计算储蓄账户利息，更改时间节点
            if (date.getMonth() == 12) {
                date = Date(date.getYear() + 1, 1, 1);//进入新年1月1日

            }
            else {
                date = Date(date.getYear(), date.getMonth() + 1, 1);//进入下个月1日
            }
            for (auto it = accounts.begin(); it != accounts.end(); it++)   (*it)->settle(date);//信用卡账户每月结算，储蓄账户每年结算
            fout << str << endl;
        }
        else if (str == 'q') {//查询范围内详情信息
            Date date1, date2;
            cin >> date1 >> date2;
       
            if (date2 < date1) {
                std::cout << "第二个日期必须大于第一个日期，请重新输入" << endl;
            }
            else if (date1.getMonth() <= 0 || date1.getMonth() > 12 || date2.getMonth() <= 0 || date2.getMonth() > 12) {
                std::cout << "请输入合法日期" << endl;
            }
            else if (date1.getDay() > date1.getCurMonDay() || date2.getDay() > date2.getCurMonDay()) {
                std::cout << "请输入合法日期" << endl;
            }
            else {
                Account::serach_find(date1, date2);//输入两个日期(xxxx-xx-xx)中间空格隔开
            }
            fout << str << " " << date1 << " " << date2 << endl;
        }
        else if (str == 'e') {//退出程序
            break;
        }
    }
    fout.close();
    std::cout << "结束时时间为：";
    std::cout << date << endl;
    std::cout << "Total: " << Account::getTotal() << endl;
    return 0;
}