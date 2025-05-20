#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
int* Allocate(int size);
void FillRand(int arr[], int const n);
void Print(int arr[], int const n);
int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, int value, int index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

int** Allocate(int rows, int cols);
void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);
int** push_rows_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, int cols, int index);
int** push_col_back(int** arr, int rows, int& cols);
int** push_col_front(int** arr, int rows, int& cols);
int** insert_col(int** arr, int rows, int& cols, int index);
int** pop_row_back(int** arr, int& rows, int cols);
int** pop_row_front(int** arr, int& rows, int cols);
int** erase_row(int** arr, int& rows, int cols, int index);
int** pop_col_back(int** arr, int rows, int& cols);
int** pop_col_front(int** arr, int rows, int& cols);
int** erase_col(int** arr, int rows, int& cols, int index);
void Clear(int**& arr, int rows);

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
	int* arr = Allocate(n);
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

#ifdef DYNAMIC_MEMORY_2
	/* Двумерный динамический массив */
	int rows;
	int cols;
	cout << "Введите количество строк:"; cin >> rows;
	cout << "Введите количество эелементов строки:"; cin >> cols;

	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Строки" << endl;
	arr = push_rows_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	int index;
	do
	{
		cout << "Введите индекс СТРОКИ массива для добавления:"; cin >> index;
		if (index<0 || index>rows)
		{
			cout << "Неверный индекс массива.\n";
			cout << "Повторите ввод\n";
		}
	} while (index<0 || index>rows);
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Колонки" << endl;
	arr = push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	do
	{
		cout << "Введите индекс КОЛОНКИ массива для добавления:"; cin >> index;
		if (index<0 || index>cols)
		{
			cout << "Неверный индекс массива.\n";
			cout << "Повторите ввод\n";
		}
	} while (index<0 || index>cols);
	arr = insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаление строк" << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	do
	{
		cout << "Введите индекс СТРОКИ массива для удаления:"; cin >> index;
		if (index<0 || index>rows)
		{
			cout << "Неверный индекс массива.\n";
			cout << "Повторите ввод\n";
		}
	} while (index<0 || index>rows);
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаление колонок" << endl;
	arr = pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	do
	{
		cout << "Введите индекс КОЛОНКИ массива для удаления:"; cin >> index;
		if (index<0 || index>cols)
		{
			cout << "Неверный индекс массива.\n";
			cout << "Повторите ввод\n";
		}
	} while (index<0 || index>cols);
	arr = erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	Clear(arr, rows);

	
#endif // DYNAMIC_MEMORY_2
}
int* Allocate(int size)
{
	int* arr = new int[size];
	return arr;
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

int** Allocate(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
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
int** push_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows + 1];
	
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, int cols, int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new int[cols] {};
	
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	rows++;
	return buffer;
}
int** push_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		buffer[cols] = 0;
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;

}
int** push_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1];
		buffer[0] = 0;
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}
int** insert_col(int** arr, int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		buffer[index] = 0;
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}
int** pop_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	rows--;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	rows--;
	return buffer;
}
int** erase_row(int** arr, int& rows, int cols, int index)
{
	int** buffer = new int* [rows - 1];
	int j = 0;
	for (int i = 0; i < rows; i++)
	{
		if (i != index)
		{
			buffer[j] = arr[i];
			j++;
		}
    }
	delete[] arr;
	rows--;
	return buffer;
}
int** pop_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
int** pop_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 1; j < cols; j++)
		{
			buffer[j - 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
int** erase_col(int** arr, int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		int k = 0;
		for (int j = 0; j < cols; j++)
		{
			if (j != index)
			{
				buffer[k++] = arr[i][j];
			}
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
void Clear(int**& arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}