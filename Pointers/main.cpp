#include<iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	cout << "Hello Pointers" << endl;

	int a = 2;
	int* pa = &a;
	cout << a << endl;//Вывод переменной
	cout << &a << endl;// Взятие адрема переменной
	cout << pa << endl;//Вывод адреса переменной а хронящегося в указателе pa
	cout << *pa << endl;


}