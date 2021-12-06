#include <iostream>
#include <execution>
#include "money.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int shillings, pounds,shillings1,pounds1;
	double pennies, pennies1;
	cout << "Введите первую сумму : ";
	cin >> pounds;
	cin >> shillings;
	cin >> pennies;
	money a(pounds, shillings, pennies);
	try
	{
		a.check();
	}
	catch (...)
	{
		cout << "Error" << endl;
		return 1;
	}

	a.Print();
	cout << endl;
	cout << "Введите вторую сумму : ";
	cin >> pounds1;
	cin >> shillings1;
	cin >> pennies1;
	money b(pounds1, shillings1, pennies1);
	try
	{
		b.check();
	}
	catch (...)
	{
		cout << "Error" << endl;
		return 1;
	}
	b.Print();
	cout << endl;
	cout << "Сумма : ";
	money result = a + b;
	result.Print();
	cout << endl;
	cout << "Разность : ";
	money result1 = a - b;
	result1.Print();
	cout << endl;
	cout << "Орерация а+= :";
	a += b;
	a.Print();
	cout << endl;
	cout << "Орерация а-= :";
	a -= b;
	a.Print();
	cout << endl;
	cout << "Унарный - а : ";
	a = -a;
	a.Print();
	cout << endl;
	cout << "a==b :";
	if (a == b)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << endl;
	cout << "a!=b :";
	if (a != b)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << endl;
	cout << "a>b :";
	if (a > b)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << endl;
	cout << "a>=b :";
	if (a >= b)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << endl;
	cout << "a<b :";
	if (a < b)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << endl;
	cout << "a<=b :";
	if (a <= b)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
