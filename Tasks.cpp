#include <iostream>
#include <cstdlib>
#include <ctime>


template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

// Вывод массивы в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";

}

template <typename T>
void arr_app(T*& arr, int length, int num) {

	// Шаг 0. Защита от лишний действий.
	if (num <= 0)
		return;

	// Шаг 1. Выделение памяти под новый массив нового размера.
	T* tmp = new T[length + num]{};

	// Шаг 2. Копирование значений сатрого массива в новый.
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];

	// Шаг 3. Освобождение памяти, выделенной под старый массив.
	delete[] arr;

	// Шаг 4. Перенаправление значений старого массива в новый.
	arr = tmp;
}

template <typename T>
void arr_del(T*& arr, int length, int num) {
	if (num <= 0)
		return;
	if (num >= length) {
		delete[] arr;
		arr = nullptr;
		return;
	}

	T* tmp = new T[length - num];
	for (int i = 0; i < length - num; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Выделение динамической памяти
	int* pointer = new int; //выделение участка динамической памяти
	// размером в тип int (4 б)

	*pointer = 7;
	std::cout << " pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;


	delete pointer; // освобождение памяти, выделенной динамически
	pointer = nullptr;

	if (pointer == nullptr)
		pointer = new int;


	*pointer = 15;
	std::cout << " pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;

	// Утечка памяти - явление, когда в связи с небрежным применением указателей 
	// в памяти остаются значения, не звязанные с какими-либо указателями.
	// Данные значения "блокируют" ячейки памяти и не дают другим программам с ними взаимодейтвовать.

	delete pointer;
	pointer = nullptr;


	// Одномерные динамические массивы
	std::cout << "Введите длинну массива -> ";
	int dsize;
	std::cin >> dsize;
	int* darr = new int[dsize];

	fill_arr(darr, dsize, 1, 11);

	std::cout << "Массив:\n";
	print_arr(darr, dsize);

	delete[] darr;



	// Области применения динамических массивов:
	// 1. Размер массива не известен на этапе написания кода;
	// 2. Размен массива должен имет возможность измениться;
	// 3. Реализация сложных структур данных.


	// Двумерные динамические массивы
	int rows = 5, cols = 4;
	//int* mx = new int[rows][cols]; // НЕ РАБОТАЕТ

	int** mx = new int* [rows];
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];


	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[] mx;


	// Задача 1. Увеличение размера массив.
	std::cout << "Введите рамер массива: -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr1, size1);

	std::cout << "Введите количество новых элементов -> ";
	std::cin >> n;
	arr_app(arr1, size1, n);
	if (n > 0)
		size1 += n;

	std::cout << "Итоговый массив:.n";
	print_arr(arr1, size1);


	// Задача 2. Уменьшение размера массива.
	std::cout << "Введите рамер массива: -> ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 10, 21);
	std::cout << "Изначальный массив:\n";
	print_arr(arr2, size2);

	std::cout << "Введите количество элементов для удаления -> ";
	std::cin >> n;
	arr_del(arr2, size2, n);
	if (n >= size2)
		size2 = 0;
	else
	if (n > 0)
		size2 -= n;

	std::cout << "Итоговый массив:.n";
	print_arr(arr2, size2);






	delete[] arr2;

	return 0;
}