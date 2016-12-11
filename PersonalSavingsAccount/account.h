#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include"date.h"
#include"accumulator.h"
#include<string>

//����
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
	Account(const Date &date,const std::string &id);//���캯��
	void record(const Date &date,double amount,const std::string &desc);//��¼һ����
	void error(const std::string &msg) const;//�������
private:
	std::string id;//�˺�
	double balance;//���
	static double total;//�����˻��ܽ��
};

//�����˻���
class SavingsAccount:public Account{
public:
	SavingsAccount(const Date &date,const std::string &id,double rate);
	double getRate() const{return rate;}
	virtual void deposit(const Date &date,double amount,const std::string &desc);//��Ǯ
	virtual void withdraw(const Date &date,double amount,const std::string &desc);//ȡǮ
	virtual void settle(const Date &date);//������Ϣ
private:
	Accumulator acc;  //���ڼ�����Ϣ
	double rate;   //����
};

//�����˻���
class CreditAccount:public Account{
public:
	CreditAccount(const Date &date,const std::string &id,double credit,double rate,double fee);
	double getCredit() const{return credit;}
	double getRate() const{return rate;}
	double getFee() const{return fee;}
	double getAvailableCredit() const{//���ö��
		if (getBalance()<0)
			return credit + getBalance();
		else
			return credit;
	}
	virtual void deposit(const Date &date,double amount,const std::string &desc);//��Ǯ
	virtual void withdraw(const Date &date,double amount,const std::string &desc);//ȡǮ
	virtual void settle(const Date &date);//������Ϣ
	virtual void show() const;
private:
	Accumulator acc;
	double credit;
	double rate;
	double fee;//���
	double getDebt() const{  //Ƿ��
		double balance = getBalance();
		return(balance<0?balance:0);
	}
};


#endif