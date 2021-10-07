#include <iostream>
#include "Vector.h"

int main() {
	setlocale(0, "");
	int n;
	std::cout << "Введите количество элементов: ";
	std::cin >> n;
	Vect<int> v(n);
	v.input();
	v.show();
	Vect<char> b(n);
	b.input();
	b.show();

	Vect<int> d(v); //конструктор копирования
	d.show();
	d.sort();
	Vect<char> a(b);
	a.sort();
	std::cout << "После сортировки: " << std::endl;
	d.show();
	a.show();
	std::cout << "Минимальное значение: " << d.min() << "\nСреднее значение: " << d.average() << "\nМаксимальное значение:  " << d.max() << std::endl;
	std::cout << "Преобразовать массив так, чтобы в первой половине располагались элементы, стоявшие в нечетных позициях, а во второй половине – в четных." << std::endl;
	//на вход поступает отсортированный массив
	d.changePosition();
	d.show();
	a.changePosition();
	a.show();
}
