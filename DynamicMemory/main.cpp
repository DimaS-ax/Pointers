#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
void FillRand(int arr[], int const n);
void FillRand(double arr[], int const n);
template<typename T>void Print(T arr[], int const n);
template<typename T> T* push_back(T arr[], int& n, const int value);
template<typename T> T* push_front(T arr[], int& n, const int value);
template<typename T> T* insert(T arr[], int& n, int value, int index);
template<typename T> T* pop_back(T arr[], int& n);
template<typename T> T* pop_front(T arr[], int& n);
template<typename T> T* erase(T arr[], int& n, int index);


void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
template<typename T> void Print(T** arr, const int rows, const int cols);
template<typename T> T** push_rows_back(T** arr, int& rows, int cols);
template<typename T> T** push_row_front(T** arr, int& rows, int cols);
template<typename T> T** insert_row(T** arr, int& rows, int cols, int index);
template<typename T> T** push_col_back(T** arr, int rows, int& cols);
template<typename T> T** push_col_front(T** arr, int rows, int& cols);
template<typename T> T** insert_col(T** arr, int rows, int& cols, int index);
template<typename T> T** pop_row_back(T** arr, int& rows, int cols);
template<typename T> T** pop_row_front(T** arr, int& rows, int cols);
template<typename T> T** erase_row(T** arr, int& rows, int cols, int index);
template<typename T> T** pop_col_back(T** arr, int rows, int& cols);
template<typename T> T** pop_col_front(T** arr, int rows, int& cols);
template<typename T> T** erase_col(T** arr, int rows, int& cols, int index);

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
	double* arr = new double[n];
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

	

	//Создаем массив указателей:
	double** arr = new double* [rows];
	//Выделяем память под строки двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new double[cols];
	}
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
	//Сначало удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//Удаляем массив указателей:
	delete[] arr;
#endif // DYNAMIC_MEMORY_2
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
		arr[i] /= 100;
	}
}
template<typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T> T* push_back(T arr[], int& n, const int value)
{
	T* buffer = new T[n + 1];
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
template<typename T> T* push_front(T arr[], int& n, const int value)
{
	T* buffer = new T[n + 1];
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
template<typename T> T* insert(T arr[], int& n, int value, int index)
{
	T* buffer = new T[n + 1];
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
template<typename T> T* pop_back(T arr[], int& n)
{
	T* buffer = new T[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T> T* pop_front(T arr[], int& n)
{
	T* buffer = new T[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T> T* erase(T arr[], int& n, int index)
{
	T* buffer = new T[n];
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
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 1000;
			arr[i][j] /= 100;
		}
	}
}
template<typename T> void Print(T** arr, const int rows, const int cols)
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
template<typename T> T** push_rows_back(T** arr, int& rows, int cols)
{
	//Создаем буферный массив указателей нужного размера:
	T** buffer = new T* [rows + 1];
	//Копируем адреса строк в буферный массив указателей:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//Удаляем исходный массив указателей:
	delete[] arr;
	//Создаем добавляемую строку и записываем ее адрес в массив указателей:
	buffer[rows] = new T[cols]{};
	//При добавлении в массив строки, количество его строк увеличивается на 1:
	rows++;
	//Возвращаем новый массив на место вызова:
	return buffer;
}
template<typename T> T** push_row_front(T** arr, int& rows, int cols)
{
	T** buffer = new T* [rows + 1];
	
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T> T** insert_row(T** arr, int& rows, int cols, int index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new T[cols] {};
	
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	rows++;
	return buffer;
}
template<typename T> T** push_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
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
template<typename T> T** push_col_front(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
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
template<typename T> T** insert_col(T** arr, int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
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
template<typename T> T** pop_row_back(T** arr, int& rows, int cols)
{
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	rows--;
	return buffer;
}
template<typename T> T** pop_row_front(T** arr, int& rows, int cols)
{
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	rows--;
	return buffer;
}
template<typename T> T** erase_row(T** arr, int& rows, int cols, int index)
{
	T** buffer = new T* [rows - 1];
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
template<typename T> T** pop_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
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
template<typename T> T** pop_col_front(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
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
template<typename T> T** erase_col(T** arr, int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
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