﻿#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
	setlocale(LC_ALL, "RU");
	int n;
	
	// Задача 1. В одномерном массиве размером в 10 элементов найдите среднее арифметическое.
	// Также посчитайте кол-во элементов, значение которых меньше найденного среднего арифметического.
	std::cout << "Задача 1. Среднее арифметическое всех элементов в массиве.\n"
		" Также кол-во элементов, которые меньше значения среднего арифметического.\n";
	
	int sum = 0, counter = 0;	// Создадим и инициализируем переменные суммы и счетчика.
	const int size = 10;	// Кол-во элементов - 10.
	int arr[size]{};		// Создадим массив и инициализируем его нулями.

	srand(time(NULL));		// Запустим генератор случайных чисел.
	std::cout << "Массив:\n{ ";
	for (int i = 0; i < size; i++) {	// Переберем в цикле каждый элемент в массиве и присвоим им случайные значения [1...10]
		arr[i] = rand() % 10 + 1;
		std::cout << arr[i] << ", ";	// также отобразим массив.
	}
	std::cout << "\b\b }" << std::endl;

	std::cout << "Среднее арифметическое = ";

	for (int i = 0; i < size; i++)		// Переберем в цикле каждый элемент в массиве и подсчитаем сумму всех элементов.
		sum += arr[i];

	std::cout << sum / (double)size << std::endl;	// Вычислим среднее арифмитическое с вещественным значением.

	std::cout << "Количество элементов, которые меньше среднего арифметического - ";

	for (int i = 0; i < size; i++)		// Переберем в цикле каждый элемент в массиве и подсчитаем кол-во элементов, которые меньше среднего арифмитического.
		if (arr[i] < sum / (double)size)
			counter++;
	std::cout << counter << std::endl << std::endl;
	
	// Задача 2. Даны два двумерных массива размерами 5 на 5 элементов.
	// Требуется сложить их между собой. Выведите в консоль результаты 
	// попарного сложения элементов обоих массивов, которые располагаются
	// в одинаковых координатах.
	std::cout << "Задача 2. Сложение двух случайных двумерных массивов размерами 5х5.\n";

	const int size1 = 5;
	int arr1[size1][size1]{};	// Создадим массив 1 и инициализируем его нулями.
	int arr2[size1][size1]{};	// Создадим массив 2 и инициализируем его нулями.

	srand(time(NULL));			// Запустим генератор случайных чисел.
	std::cout << "Массив 1:\n";
	for (int i = 0; i < size1; i++) {		// Переберем в цикле каждый элемент в массиве 1 и присвоим им случайные значения [0...9] 
		std::cout << "{ ";
		for (int j = 0; j < size1; j++) {
			arr1[i][j] = rand() % 10;
			std::cout << arr1[i][j] << ", ";	// также отобразим массив.
		}
		std::cout << "\b\b }";
		if (i < size1-1)			// С помощью конструкции if..else избавимся от запятой в конце массива.
			std::cout << ",\n";
		else
			std::cout << "\n";
	}
	//std::cout << "\b\n\n";
	std::cout << "\nМассив 2:\n";
	for (int i = 0; i < size1; i++) {		// Переберем в цикле каждый элемент в массиве 2 и присвоим им случайные значения [0...9]
		std::cout << "{ ";
		for (int j = 0; j < size1; j++) {
			arr2[i][j] = rand() % 10;
			std::cout << arr2[i][j] << ", ";	// также отобразим массив.
		}
		std::cout << "\b\b }";
		if (i < size1 - 1)			// С помощью конструкции if..else избавимся от запятой в конце массива.
			std::cout << ",\n";
		else
			std::cout << "\n";
	}
	//std::cout << "\b\n\n";
	std::cout << "\nРезультат сложение двух массивов:\n";
	for (int i = 0; i < size1; i++) {		// Переберем в цикле каждый элемент в массивах 1 и 2.
		std::cout << "{ ";
		for (int j = 0; j < size1; j++)
			std::cout << arr1[i][j] + arr2[i][j] << ", ";	// Суммируем каждый элемент в массивах 1 и 2.
		std::cout << "\b\b }";
		if (i < size1 - 1)			// С помощью конструкции if..else избавимся от запятой в конце массива.
			std::cout << ",\n";
		else
			std::cout << "\n";
	}
	//std::cout << "\b\n\n";
	
	// Задача 3. Пользователь вводит шестизначное число. Если число введено неверно,
	// программа завершает свою работу. Иначе, программа в цикле помещает все его цифры 
	// в одномерный массив размером в 6 элементов и выводит его на экран.

	std::cout << "Задача 3. Внесение числа в массив.\n";
	std::cout << "Введите шестизначное число -> ";
	std::cin >> n;

	int m, counter2 = 0;	// Создадим две переменные и инициализируем только счетчик.
	m = n;		// Присвоим значение вводимого числа в переменную m.
	do {		// В цикле do while определим разрядность вводимого числа.
		m /= 10;
		counter2++;
	} while (m); // тоже что и m != 0.

	if (counter2 != 6)	// При не правильном вводе числа (не шестизначное), выведим ошибку ввода.
		std::cout << "Ошибка ввода!\n\n";
	else {				// При правильном вводе числа (оно шестизначное), вводим число в массив.
		const int size3 = 6;
		int arr3[size3]{};		// Создадим массив и инициализируем его нулями.

		std::cout << "Получим массив: { ";
		for (int i = 0, j=100000; i < size3; i++, j/=10) {	// В цикле переменной i будем перебирать элементы массива от начала и до конца,
			m = n;											// переменной j будем получать цифры из введенного числа от первого до последнего и записывать их в значения элементов массива.
			arr3[i] = (m / j) % 10;			// переменную m на каждой итерации обновляем.
			std::cout << arr3[i] << ", ";	// вывод в консоль каждого элемента массива. 
		}
		std::cout << "\b\b }" << std::endl;
	}
	std::cout << std::endl;


	return 0;
}