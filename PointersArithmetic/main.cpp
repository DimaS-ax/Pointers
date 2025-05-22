#include<iostream>
using namespace std;
int* Allocate(int size);
int** Allocate(int rows, int cols);
void Clear(int**& arr, int rows);
//#define DYNAMIC_ONE_DIMENSIONAL_ARRAY
#define TWO_DIMENSIONAL_DYNAMIC_ARRAY
void main()
{
	setlocale(LC_ALL, "ru");

#ifdef DYNAMIC_ONE_DIMENSIONAL_ARRAY
	int n = 5;
	int* array = Allocate(n);
	for (int i = 0; i < n; i++)
	{
		array[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << "\t";
	}
	delete[] array;
#endif // DYNAMIC_ONE_DIMENSIONAL_ARRAY


#ifdef TWO_DIMENSIONAL_DYNAMIC_ARRAY
	int rows;
	int cols;
	cout << "Введите размер строки массива:"; cin >> rows;
	cout << " Введите размер колонок: "; cin >> cols;

	// Создание массива
	/*int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}*/
	int** arr = Allocate(rows, cols);

	//Заполнение массива последовательными числами
	/*for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = i * cols + j;
		}
	}*/

	//Заполнение массива числами, с помощью арифметики указателей и оператора разыменования
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(*(arr + i) + j) = i * cols + j;
		}
	}

	//Вывод массива на экран с помощью цыкла "FOR"
	/*for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}*/

	//Вывод массива на экран через указатель на элементы строки
	for (int i = 0; i < rows; i++)
	{
		int* row_element = arr[i];//Указатель на нулевой элемент двумерного массива
		for (int j = 0; j < cols; j++)
		{
			cout << *row_element << "\t";// оператор разыменования _*_
			row_element++;//Указатель переходит по элементам массива
		}
		cout << endl;
	}



	// Освобождение памяти
	/*for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;*/
	Clear(arr, rows);

#endif // TWO_DIMENSIONAL_DYNAMIC_ARRAY

	
}
int* Allocate(int size)
{
	int* arr = new int[size];
	return arr;
}
int** Allocate(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int**& arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}
