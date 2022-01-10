#include"accumulator.h"
Accumulator::Accumulator(Date date, double value):lastDate(date),value(value),sum(0){

}
//����ָ�����ڵİ����ۼ�ֵ
double Accumulator::getSum(Date date) const {
	//cout << "ʱ������" << (date - lastDate) << " �ۼӺͣ�" << sum + value * (date - lastDate) << endl;
	return sum + value * (date - lastDate);
}
//�ı���ֵ
void Accumulator::change(Date date, double value) {//value���˻��еĽ����
	sum = getSum(date);//���������ǰ�İ����ۼ�ֵ
	lastDate = date;//�޸��������
	this->value = value;//�ı䵱ǰֵ
}
void Accumulator::reset(Date date, double value) {
	lastDate = date;
	this -> value = value;
	sum = 0;
}