#include<iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	cout << "Hello Pointers" << endl;

	int a = 2;
	int* pa = &a;
	cout << a << endl;//����� ����������
	cout << &a << endl;// ������ ������ ����������
	cout << pa << endl;//����� ������ ���������� � ����������� � ��������� pa
	cout << *pa << endl;


}