#include<iostream>
using namespace std;
#define delimetr "-----------------------\n"
void FillRand(int*& arr, int& rows)
{
	for (int i = 0; i < rows; i++)arr[i] = i;
}
void FillRand(int** Arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)Arr[i][j] = i * cols + j;
	}
}
template<typename T>void Print(T*& arr, int& rows)
{
	for (int i = 0; i < rows; i++)cout << arr[i] << "\t";
	cout << endl;
}
template<typename T>void Print(T**& Arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cout << Arr[i][j] << "\t";
		cout << endl;
	}
}
template<typename T>void Allocate(T** arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++)arr[i] = new T[cols];
}
template<typename T>void pushBack(T*& arr, int& size, const T& element)
{
	T* buffer = new T[size + 1];
	for (int i = 0; i < size; i++)buffer[i] = arr[i];
	buffer[size] = element;
	delete[] arr;
	arr = buffer;
	size++;
}
template<typename T>void pushFront(T*& arr, int& size, const T& element)
{
	T* buffer = new T[size + 1];
	buffer[0] = element;
	for (int i = 0; i < size; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	size++;
}
template<typename T>void pushInsert(T*& arr, int& size, int index, const T& element)
{
	T* buffer = new T[size + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	buffer[index] = element;
	for (int i = index; i < size; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	size++;
}
template<typename T>void popBack(T*& arr, int& size)
{
	T* buffer = new T[size - 1];
	for (int i = 0; i < size - 1; i++)buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	size--;
}
template<typename T>void popFront(T*& arr, int& size)
{
	T* buffer = new T[size - 1];
	for (int i = 0; i < size - 1; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	size--;
}
template<typename T>void popErase(T*& arr, int& size, int index)
{
	T* buffer = new T[size - 1];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != index)
		{
			buffer[j] = arr[i];
			j++;
		}
	}
	delete[] arr;
	arr = buffer;
	size--;
}
template<typename T>void pushColBack(T** arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void pushColFront(T** arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		buffer[0] = 0;
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void InsertCol(T** arr, int& rows, int& cols, int& index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		buffer[index] = 0;
		for (int j = index; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void popColBack(T** arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void popColFront(T** arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 1; j < cols; j++)buffer[j - 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void eraseCol(T** arr, int& rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void Clear(T**& Arr, int& rows)
{
	for (int i = 0; i < rows; i++)delete[] Arr[i];
	delete[] Arr;
}
void main()
{
	setlocale(LC_ALL, "ru");
	int size = 3;
	int* arr = new int[size];
	FillRand(arr, size);
	Print(arr, size);
	int Element;
	cout << "Введите элемент для добавления в массив:"; cin >> Element;
	pushBack(arr, size, Element);
	Print(arr, size);
	cout << "Введите элемент для добавления в массив:"; cin >> Element;
	pushFront(arr, size, Element);
	Print(arr, size);
	int index;
	cout << "Введите индекс для добавления в массив:"; cin >> index;
	cout << "Введите элемент для добавления в массив:"; cin >> Element;
	pushInsert(arr, size, index, Element);
	Print(arr, size);
	popBack(arr, size);
	Print(arr, size);
	popFront(arr, size);
	Print(arr, size);
	cout << "Введите индекс для удаления элемента:"; cin >> index;
	popErase(arr, size, index);
	Print(arr, size);
	delete[] arr;
	cout << delimetr;
	cout << delimetr;
	int rows = 3;
	int cols = 3;
	int** Arr = new int* [rows];
	Allocate(Arr, rows, cols);
	FillRand(Arr, rows, cols);
	Print(Arr, rows, cols);
	cout << delimetr;
	int* newRow = new int[3] {};//Объявили новую строку, добавляемую в 2Д массив
	pushBack(Arr, rows, newRow);
	Print(Arr, rows, cols);
	cout << delimetr;
	int* newRow2 = new int[3] {};//Объявили новую строку, добавляемую в начало 2Д массива
	pushFront(Arr, rows, newRow2);
	Print(Arr, rows, cols);
	cout << delimetr;
	int* newRow3 = new int[3] {};//Объявили новую строку
	cout << "Введите индекс для добавления строчки:"; cin >> index;
	pushInsert(Arr, rows, index, newRow3);
	Print(Arr, rows, cols);
	cout << delimetr;
	popBack(Arr, rows);
	Print(Arr, rows, cols);
	cout << delimetr;
	popFront(Arr, rows);
	Print(Arr, rows, cols);
	cout << delimetr;
	cout << "Введите индекс для удаления строчки:"; cin >> index;
	popErase(Arr, rows, index);
	Print(Arr, rows, cols);
	cout << delimetr;
	pushColBack(Arr, rows, cols);
	Print(Arr, rows, cols);
	cout << delimetr;
	pushColFront(Arr, rows, cols);
	Print(Arr, rows, cols);
	cout << delimetr;
	cout << "Введите индекс для добавления колонки:"; cin >> index;
	InsertCol(Arr, rows, cols, index);
	Print(Arr, rows, cols);
	cout << delimetr;
	popColBack(Arr, rows, cols);
	Print(Arr, rows, cols);
	cout << delimetr;
	popColFront(Arr, rows, cols);
	Print(Arr, rows, cols);
	cout << delimetr;
	cout << "Введите индекс для удаления колонки:"; cin >> index;
	eraseCol(Arr, rows, cols, index);
	Print(Arr, rows, cols);
	Clear(Arr, rows);
}