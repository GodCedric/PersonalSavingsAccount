#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include"date.h"
#include"accumulator.h"
#include<string>

//基类
class Account{
public:
	const std::string getId() const{return id;}
	double getBalance() const {return balance;}
	static double getTotal(){return total;}
	virtual void deposit(const Date &date,double amount,const std::string &desc)=0;
	virtual void withdraw(const Date &date,double amount,const std::string &desc)=0;
	virtual void settle(const Date &date)=0;
	virtual void show() const;
protected:
	Account(const Date &date,const std::string &id);//构造函数
	void record(const Date &date,double amount,const std::string &desc);//记录一笔账
	void error(const std::string &msg) const;//报告错误
private:
	std::string id;//账号
	double balance;//余额
	static double total;//所有账户总金额
};

//储蓄账户类
class SavingsAccount:public Account{
public:
	SavingsAccount(const Date &date,const std::string &id,double rate);
	double getRate() const{return rate;}
	virtual void deposit(const Date &date,double amount,const std::string &desc);//存钱
	virtual void withdraw(const Date &date,double amount,const std::string &desc);//取钱
	virtual void settle(const Date &date);//结算利息
private:
	Accumulator acc;  //用于计算利息
	double rate;   //利率
};

//信用账户类
class CreditAccount:public Account{
public:
	CreditAccount(const Date &date,const std::string &id,double credit,double rate,double fee);
	double getCredit() const{return credit;}
	double getRate() const{return rate;}
	double getFee() const{return fee;}
	double getAvailableCredit() const{//可用额度
		if (getBalance()<0)
			return credit + getBalance();
		else
			return credit;
	}
	virtual void deposit(const Date &date,double amount,const std::string &desc);//存钱
	virtual void withdraw(const Date &date,double amount,const std::string &desc);//取钱
	virtual void settle(const Date &date);//结算利息
	virtual void show() const;
private:
	Accumulator acc;
	double credit;
	double rate;
	double fee;//年费
	double getDebt() const{  //欠款
		double balance = getBalance();
		return(balance<0?balance:0);
	}
};


#endif