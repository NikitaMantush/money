#include "money.h"
#include<iostream>
money::money(int pd, int sh, double p)
{
	this->pd = pd;
	this->sh = sh;
	this->p = p;
}
void money::check()
{
	double p1;
	int p2;
	p1 = p * 2;
	p2 = static_cast<int>(p1);
	if (p2 != p1 || p > 12|| sh>20)
	{
		throw std::overflow_error("Errore");
	}
}
void money:: SetSh(int sh)
{
	this->sh = sh;
}
void money::SetPd(int pd)
{
	this->pd = pd;
}
void money::SetP(double p)
{
	this->p = p;
}
int money::GetPd()
{
	return pd;
}
int money::GetSh()
{
	return sh;
}
double money::GetP()
{
	return p;
}
money operator+(money& first, money& second)
{

	int phund, shill, pen1;
	double pen, pen2;
	phund = first.pd + second.pd;
	shill = first.sh + second.sh;
	pen = first.p + second.p;
	pen1 = static_cast<int>(pen);
	if (pen1==pen)
	{
		shill += pen1 / 12;
		pen1 %= 12;
		phund += shill / 20;
		shill %= 20;
		money temp(phund, shill, pen1);
		return temp;
	}
	else if (pen1 != pen)
	{
		shill += pen1 / 12;
		pen1 %= 12;
		phund += shill / 20;
		shill %= 20;
		pen2 = static_cast<double>(pen1) + 0.5;
		money temp(phund, shill, pen2);
		return temp;
	}

}
money operator-(money& first, money& second)
{

	int phund, shill, pen1;
	double pen, pen2;
	phund = first.pd - second.pd;
	shill = first.sh - second.sh;
	pen = first.p - second.p;
	pen1 = static_cast<int>(pen);
	if (pen1 == pen)
	{
		shill += pen1 / 12;
		pen1 %= 12;
		phund += shill / 20;
		shill %= 20;
		if (phund < 0 && phund != 0)
		{
			money temp(phund, abs(shill), abs(pen1));
			return temp;
		}
		if (phund == 0 && shill < 0)
		{
			money temp(phund, shill, abs(pen1));
			return temp;
		}
		if (phund == 0 && shill == 0 && pen1 < 0)
		{
			money temp(phund, shill, pen1);
			return temp;
		}
		if (phund > 0 && shill > 0 && pen1 > 0)
		{
			money temp(phund, shill, pen1);
			return temp;
		}
	}
	else if (pen1 != pen)
	{
		shill += pen1 / 12;
		pen1 %= 12;
		phund += shill / 20;
		shill %= 20;
		pen2 = static_cast<double>(pen1) + 0.5;
		if (phund<0 && phund!=0)
		{
			money temp(phund, abs(shill), abs(pen2));
			return temp;
		}
		if (phund == 0 && shill<0)
		{
			money temp(phund, shill, abs(pen2));
			return temp;
		}
		if (phund==0 && shill==0 && pen2<0)
		{
			money temp(phund, shill, pen2);
			return temp;
		}
		if (phund > 0 && shill > 0 && pen2 > 0)
		{
			money temp(phund, shill, pen2);
			return temp;
		}
	}

}
money& money::operator+=( money& second)
{
	int phund, shill, pen1;
	double pen, pen2;
	phund = this->pd + second.pd;
	shill = this->sh + second.sh;
	pen = this->p + second.p;
	pen1 = static_cast<int>(pen);
	if (pen1 == pen)
	{
		shill += pen1 / 12;
		pen1 %= 12;
		phund += shill / 20;
		shill %= 20;
		this->pd=phund;
		this->sh=shill;
		this->p=pen1;
		return *this;
	}
	else if (pen1 != pen)
	{
		shill += pen1 / 12;
		pen1 %= 12;
		phund += shill / 20;
		shill %= 20;
		pen2 = static_cast<double>(pen1) + 0.5;
		this->pd = phund;
		this->sh = shill;
		this->p = pen2;
		return *this;
	}
}
money& money::operator-=(money& second)
{
	int phund, shill, pen1;
	double pen, pen2;
	phund = this->pd - second.pd;
	shill = this->sh - second.sh;
	pen = this->p - second.p;
	pen1 = static_cast<int>(pen);
	if (pen1 == pen)
	{
		shill += pen1 / 12;
		pen1 %= 12;
		phund += shill / 20;
		shill %= 20;
		this->pd = phund;
		this->sh = shill;
		this->p = pen1;
		return *this;
	}
	else if (pen1 != pen)
	{
		shill += pen1 / 12;
		pen1 %= 12;
		phund += shill / 20;
		shill %= 20;
		pen2 = static_cast<double>(pen1) + 0.5;
		this->pd = phund;
		this->sh = shill;
		this->p = pen2;
		return *this;
	}
}
money money::operator-()
{
	return money(-pd, sh, p);
}
bool operator==(money& first, money& second)
{
	if (first.pd == second.pd && first.sh == second.sh && first.p == second.p)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!=(money& first, money& second)
{
	if (first.pd != second.pd || first.sh != second.sh || first.p != second.p)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>(money& first, money& second)
{
	double sum1 = first.pd * 240 + first.sh * 20 + first.p;
	double sum2 = second.pd * 240 + second.sh * 20 + second.p;
	if (sum1>sum2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>=(money& first, money& second)
{

	double sum1 = first.pd * 240 + first.sh * 20 + first.p;
	double sum2 = second.pd * 240 + second.sh * 20 + second.p;
	if (sum1>=sum2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<(money& first, money& second)
{

	double sum1 = first.pd * 240 + first.sh * 20 + first.p;
	double sum2 = second.pd * 240 + second.sh * 20 + second.p;
	if (sum1<sum2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<=(money& first, money& second)
{

	double sum1 = first.pd * 240 + first.sh * 20 + first.p;
	double sum2 = second.pd * 240 + second.sh * 20 + second.p;
	if (sum1 <= sum2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
