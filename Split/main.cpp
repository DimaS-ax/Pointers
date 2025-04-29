#include<iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	int size = 10;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	int* odd = new int[size];
	int* even = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0)
		{
			odd[i] = arr[i];
			cout << odd[i] << "\t";
		}
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{ 
		if (arr[i] % 2 == 0)
		{
			even[i] = arr[i];
			cout << even[i] << "\t";
	    }
	}
	delete[] arr, odd, even;
}