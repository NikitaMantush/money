#pragma once
#include<iostream>
using namespace std;

class money
{
private:
	int pd;
	int sh;
	double p;
public:
	money(int, int, double);
	money()
	{
		pd = 0;
		sh = 0;
		p = 0;
	}
	void Print()
	{
		if (pd != 0 && sh != 0 && p != 0)
		{
			cout << pd << "pd " << sh << "sh " << p << "p ";
		}
		if (pd==0 && sh!=0 && p!=0)
		{
			cout << sh << "sh " << p << "p ";
		}
		if(pd!=0 && sh==0 && p!=0)
		{
			cout << pd << "pd "<< p << "p ";
		}
		if (pd!=0 && sh!=0 && p==0)
		{
			cout << pd << "pd " << sh << "sh ";

		}
	    if (pd == 0 && sh == 0 && p != 0)
		{
			cout << p << "p ";

		}
	    if (pd != 0 && sh == 0 && p == 0)
		{
			cout << pd << "pd ";

		}
	    if (pd == 0 && sh != 0 && p == 0)
		{

			cout << sh << "sh ";
		}
		if (pd==0 && sh==0 && p==0)
		{
			cout<<"0p. "
		}
		
	}
	void SetPd(int);
	int GetSh();
	void SetSh(int);
	int GetPd();
	void SetP(double);
	double GetP();
	void check();
	friend money operator+( money& first, money& second);
	friend money operator-( money& first, money& second);
    money operator-();
    money& operator+=(money&);
    money& operator-=(money&);
	friend bool operator==(money& first, money& second);
	friend bool operator!=(money& first, money& second);
	friend bool operator>(money& first, money& second);
	friend bool operator>=(money& first, money& second);
	friend bool operator<(money& first, money& second);
	friend bool operator<=(money& first, money& second);
};

