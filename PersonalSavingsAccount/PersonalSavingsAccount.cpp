#include<iostream>
#include"account.h"

using namespace std;

int main(){
	Date date(2016,12,11);
	//Ω®¡¢’Àªß
	SavingsAccount sa1(date,"LiuYang",0.015);
	SavingsAccount sa2(date,"Anqi",0.015);
	CreditAccount ca(date,"GodCedric",10000,0.0005,50);
	Account *account[]={&sa1,&sa2,&ca};
	const int n = sizeof(account)/sizeof(Account*);
	cout<<"(d)deposit (w)withdraw (s)show (c)change day (n)next month (e)exit"<<endl;
	char cmd;
	do{
		date.show();
		cout<<"\tTotal: "<<Account::getTotal()<<"\tcommand>";
		int index,day;
		double amount;
		string desc;
		cin>>cmd;
		switch(cmd){
		case 'd':
			cin>>index>>amount;
			getline(cin,desc);
			account[index]->deposit(date,amount,desc);
			break;
		case 'w':
			cin>>index>>amount;
			getline(cin,desc);
			account[index]->withdraw(date,amount,desc);
			break;
		case 's':
			for(int i=0;i<n;i++){
				cout<<"["<<i<<"]";
				account[i]->show();
				cout<<endl;
			}
			break;
		case 'c':
			cin>>day;
			if(day<date.getDay())
				cout<<"You cannot specify a previous day";
			else if(day>date.getMaxDay())
				cout<<"Invalid day";
			else
				date=Date(date.getYear(),date.getMonth(),day);
			break;
		case 'n':
			if (date.getMonth()==12)
				date=Date(date.getYear()+1,1,1);
			else
				date=Date(date.getYear(),date.getMonth()+1,1);
			for (int i=0;i<n;i++)
				account[i]->settle(date);
			break;
		}
	}while(cmd!='e');

	return 0;
}