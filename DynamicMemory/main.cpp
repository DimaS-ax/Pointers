#include<iostream>
using namespace std;
void FillRand(int arr[], int const n);
void Print(int arr[], int const n);
void push_front(int*& arr, int& n);
void insert(int*& arr, int& n, int var, int index);
void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Ввидите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	push_front(arr, n);
	Print(arr, n);
	int var;
	cout << "Ввидите значение элемента: "; cin >> var;
	int index;
	cout << "Ввидите индекс массива: "; cin >> index;
	insert(arr, n, var, index);
	Print(arr, n);
	pop_back(arr, n);
	Print(arr, n);
	pop_front(arr, n);
	Print(arr, n);
	cout << "Укажите индекс удаляемого элемента: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], int const n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], int const n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void push_front(int*& arr, int& n)
{
	int* brr = new int[n + 1];
	FillRand(brr, n + 1);
	n++;
	delete[] arr;
	arr = brr;
}
void insert(int*& arr, int& n, int var, int index)
{
	int* brr = new int[n + 1];
	FillRand(brr, n + 1);
	if (brr[index]) brr[index] = var;
	n++;
	delete[] arr;
	arr = brr;
}
void pop_back(int*& arr, int& n)
{
	n--;
	int* brr = new int[n];
	for (int i = 0; i < n; i++)
	{
		brr[i] = arr[i];
	}
	delete[]arr;
	arr = brr;
}
void pop_front(int*& arr, int& n)
{
	int* brr = new int[n--];
	for (int i = 0; i < n; i++)
	{
		brr[i] = arr[i + 1];
	}
	delete[] arr;
	arr = brr;
}
void erase(int*& arr, int& n, int index)
{
	int* brr = new int[n];
	for (int i = 0; i < n; i++)
	{
		brr[i] = arr[i];
	}
	if (index < n)
	{
		for (int i = index; i < n - 1; i++)
		{
			brr[i] = brr[i + 1];
		}
		n--;
	}
	delete[] arr;
	arr = brr;
}
