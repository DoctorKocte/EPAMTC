#include <iostream>
#include "Vector.h"

int main() {
	setlocale(0, "");
	int n;
	std::cout << "Введите количество элементов: ";
	std::cin >> n;
	Vect<int> v(n);
	//Vect<char> b(n);
	v.input();
	v.show();
	Vect<int> d(v); //конструктор копирования

	d.show();
	d.sort();
	d.show();
	std::cout << "Минимальное значение: " << d.min() << "\nСреднее значение: " << d.average() << "\nМаксимальное значение:  " << d.max() << std::endl;
	std::cout << "Преобразовать массив так, чтобы в первой половине располагались элементы, стоявшие в нечетных позициях, а во второй половине – в четных" << std::endl;
	d.changePosition();
	d.show();
}
