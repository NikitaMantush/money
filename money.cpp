#include "money.h"
#include<iostream>
money::money(int pd, int sh, double p): pd(pd), sh(sh),p(p)
{
	
}
istream& operator>> (istream& in, money& main)
{
	in >> main.pd;
	in >> main.sh;
	in >> main.p;
	main.ExceptionHandling(main, std::cout);
	return in;
}
void money::check()
{

	double p1;
	int p2;
	p1 = p * 2;
	p2 = static_cast<int>(p1);
	if (p > 12 || p<0 || p1!=p2)
	{
		throw std::exception("The number of pence does not meet the condition");
	}
	if (pd > 10000000000 || pd<0 )
	{
		throw std::exception("The number of pounds does not meet the condition");
	}
	if (sh>20||sh<0)
	{
		throw std::exception("The number of shillings does not meet the condition");
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
const int money::GetPd()
{
	return pd;
}
const int money::GetSh()
{
	return sh;
}
const double money::GetP()
{
	return p;
}
money operator+(const money& first,const money& second)
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
money operator-(const money& first, const money& second)
{

	int phund=0, shill=0;
	double pen=0.0;
	int n=0;
	if (first >= second)
	{
		pen = first.p - second.p;
		if (first.p<second.p)
		{
			n -= 1;
			pen += 12.0;
		}
		shill = first.sh + n- second.sh;
		if (first.sh+n<second.sh)
		{
			phund -= 1;
			shill += 20;
		}
		phund = first.pd - second.pd;
	}
	else
	{
		pen = second.p - first.p;
		if (second.p < first.p)
		{
			n -= 1;
			pen += 12.0;
		}
		shill = second.sh + n - first.sh;
		if (second.sh + n < first.sh)
		{
			phund -= 1;
			shill += 20;
		}
		phund = second.pd - first.pd;
		pen * -1; shill * -1; phund * -1;
	}
	return money(phund, shill, pen);

}
money operator+= (money& first, const money& second)
{
	first = (first + second);
	return first;

}
money operator-= (money& first, const money& second)
{
	first = (first - second);
	return first;

}
money money::operator-()
{
	return money(-pd, sh, p);
}
bool operator==(const money& first, const money& second)
{
	if (first.pd==second.pd && first.sh==second.sh && first.p==second.p)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!=(const money& first,const money& second)
{
	if (first==second)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator>(const money& first,const money& second)
{
	if (first.pd >= second.pd)
	{
		if (first.pd > second.pd)
		{
			return true;
		}
		else if (first.sh >= second.sh)
		{
			if (first.sh > second.sh)
			{
				return true;
			}
			else if (first.p > second.p)
			{
				return true;
			}
		}
	}

	return false;
}
bool operator>=(const money& first, const money& second)
{
	if (first==second || first>second)
	{
		return true;
	}
}
bool operator<(const money& first,const  money& second)
{
	if (first.pd <= second.pd)
	{
		if (first.pd < second.pd)
		{
			return true;
		}
		else if (first.sh <= second.sh)
		{
			if (first.sh < second.sh)
			{
				return true;
			}
			else if (first.p < second.p)
			{
				return true;
			}
		}
	}
		return false;
	
}
bool operator<=(const money& first, const money& second)
{

	if (first == second|| first < second)
	{
		return true;
	}
}
