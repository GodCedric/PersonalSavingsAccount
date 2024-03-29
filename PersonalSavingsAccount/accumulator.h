#ifndef _ACCUMULATOR_H_
#define _ACCUMULATOR_H_
#include"date.h"

class Accumulator{         //某个数值按月累加
public:
	Accumulator(const Date &date,double value):lastDate(date),value(value),sum(0){}
	//获得日期date的累加结果
	double getSum(const Date &date) const{
		return sum+value*(date - lastDate);
	}
	//在date将数值变为value
	void change(const Date &date,double value){
		sum = getSum(date);
		lastDate=date;this->value=value;
	}
	//初始化，将日期变为date，数值变为value，累加器清零
	void reset(const Date &date,double value){
		lastDate=date;this->value=value;sum=0;
	}

private:
	Date lastDate;//上次变更数值的日期
	double value;//数值的当前值
	double sum;//数值按日累加之和
};

#endif