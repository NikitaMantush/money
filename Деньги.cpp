#include <iostream>
#include <execution>
#include "money.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	money first, second;
	cout << "Введите первую сумму : ";
	cin >> first;
	first.Print(cout);
	cout << endl;
	cout << "Введите вторую сумму : ";
	cin >> second;
	second.Print(cout);
	cout << endl;
	cout << "Сумма : ";
	money result = first + second;
	result.Print(cout);
	cout << endl;
	cout << "Разность : ";
	money result1 = first - second;
	result1.Print(cout);
	cout << endl;
	cout << "Орерация first += second :";
	first += second;
	first.Print(cout);
	cout << endl;
	cout << "Орерация first -= second :";
	first -= second;
	first.Print(cout);
	cout << endl;
	cout << "Унарный - first  : ";
	first = -first;
	first.Print(cout);
	cout << endl;
	cout << "first == second :";
	cout << "it is " << (first == second);
	cout << endl;
	cout << "first != second :";
	cout << "it is " << (first != second);
	cout << endl;
	cout << "first > second :";
	cout << "it is " << (first > second);
	cout << endl;
	cout << "first >= second :";
	cout << "it is " << (first >= second);
	cout << endl;
	cout << "first < second :";
	cout << "it is " << (first < second);
	cout << endl;
	cout << "first <= second :";
	cout << "it is " << (first <= second);
}
