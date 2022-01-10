#include"accumulator.h"
Accumulator::Accumulator(Date date, double value):lastDate(date),value(value),sum(0){

}
//返回指定日期的按日累加值
double Accumulator::getSum(Date date) const {
	//cout << "时间间隔：" << (date - lastDate) << " 累加和：" << sum + value * (date - lastDate) << endl;
	return sum + value * (date - lastDate);
}
//改变数值
void Accumulator::change(Date date, double value) {//value是账户中的金额数
	sum = getSum(date);//计算该日期前的按日累加值
	lastDate = date;//修改最后日期
	this->value = value;//改变当前值
}
void Accumulator::reset(Date date, double value) {
	lastDate = date;
	this -> value = value;
	sum = 0;
}