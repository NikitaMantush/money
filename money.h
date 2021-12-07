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
	void Print(ostream& os)
	{
		if (pd != 0 && sh != 0 && p != 0)
		{
			os << pd << "pd " << sh << "sh " << p << "p ";
		}
		if (pd==0 && sh!=0 && p!=0)
		{
			os << sh << "sh " << p << "p ";
		}
		if(pd!=0 && sh==0 && p!=0)
		{
			os << pd << "pd "<< p << "p ";
		}
		if (pd!=0 && sh!=0 && p==0)
		{
			os << pd << "pd " << sh << "sh ";

		}
	    if (pd == 0 && sh == 0 && p != 0)
		{
			os << p << "p ";

		}
	    if (pd != 0 && sh == 0 && p == 0)
		{
			os << pd << "pd ";

		}
	    if (pd == 0 && sh != 0 && p == 0)
		{

			os << sh << "sh ";
		}
		if (pd == 0 && sh == 0 && p == 0)
		{
			os << "0p. ";
		}
		
	}
	void SetPd(int);
	const int GetSh();
	void SetSh(int);
	const int GetPd();
	void SetP(double);
	const double GetP();
	void check();
	const void ExceptionHandling(money a , ostream& oc)
	{
		try
		{
			a.check();
		}
		catch (const exception& exp)
		{
			oc << exp.what() << endl;
			exit(0);
		}
	}
    money operator-();
	friend istream& operator>> (istream& in, money& main);
	friend money operator+(const money& first,const money& second);
	friend money operator-(const money& first, const money& second);
    friend money operator+=(money& first, const money& second);
	friend money operator-= (money& first, const money& second);
	friend bool operator==(const money& first,const money& second);
	friend bool operator!=(const money& first,const  money& second);
	friend bool operator>(const money& first,const money& second);
	friend bool operator>=(const money& first,const money& second);
	friend bool operator<(const money& first,const money& second);
	friend bool operator<=(const money& first,const money& second);
};

