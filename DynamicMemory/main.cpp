#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
void FillRand(int arr[], int const n);
void Print(int arr[], int const n);
int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, int value, int index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);


void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);
int** push_rows_back(int** arr, int& rows, int cols);

#define tab "\t"
#define delimeter "\n------------------------------------\n"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Ввидите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n); //Заполняет массив
	Print(arr, n); //Выводит массив
	int value;
	cout << "Введите значение элемента: "; cin >> value;
	arr = push_back(arr, n, value); //Добавляет последний элемент
	Print(arr, n);
	cout << "Введите значение элемента: "; cin >> value;
	arr = push_front(arr, n, value);//Добавляет первый элемент
	Print(arr, n);
	int index;
	cout << "Введите значение индекса: "; cin >> index;
	cout << "Введите значение элемента: "; cin >> value;
	arr = insert(arr, n, value, index);// Добавляет элемент массива по индексу
	Print(arr, n);
	arr = pop_back(arr, n);//Удаляет последний элемент
	Print(arr, n);
	arr = pop_front(arr, n);//Удаляет первый элемент
	Print(arr, n);
	cout << "Введите значение индекса: "; cin >> index;
	arr = erase(arr, n, index);//Удаляет элемент по индексу
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	                   /* Двумерный динамический массив */
	int rows;
	int cols;
	cout << "Введите количество строк:"; cin >> rows;
	cout << "Введите количество эелементов строки:"; cin >> cols;

	//Создаем массив указателей:
	int** arr = new int* [rows];
	//Выделяем память под строки двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	
	arr = push_rows_back(arr, rows, cols);
	Print(arr, rows, cols);

	//Сначало удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//Удаляем массив указателей:
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
int* push_back(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	if (buffer[index])
	{
		for (int i = index; i < n - 1; i++)
		{
			buffer[i] = buffer[i + 1];
		}
		n--;
	}
	delete[] arr;
	arr = buffer;
	return arr;
}


void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << delimeter;
	cout << endl;
}
int** push_rows_back(int** arr, int& rows, int cols)
{
	//Создаем буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];
	//Копируем адреса строк в буферный массив указателей:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//Удаляем исходный массив указателей:
	delete[] arr;
	//Создаем добавляемую строку и записываем ее адрес в массив указателей:
	buffer[rows] = new int[cols]{};
	//При добавлении в массив строки, количество его строк увеличивается на 1:
	rows++;
	//Возвращаем новый массив на место вызова:
	return buffer;
}
