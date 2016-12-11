#ifndef _DATE_H_
#define _DATE_H_

class Date{
public:
	Date(int year,int month,int day);
	int getYear() const{return year;}
	int getMonth() const{return month;}
	int getDay() const{return day;}
	int getMaxDay() const;
	bool isLeapYear() const{return year%4==0 && year%100!=0||year%400==0;}
	void show() const;
	int operator- (const Date &date) const{return totalDays-date.totalDays;}
private:
	int year;
	int month;
	int day;
	int totalDays;
};

#endif