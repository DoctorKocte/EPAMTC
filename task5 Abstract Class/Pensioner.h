#pragma once
#include "Adult.h"

class Pensioner : public Adult {
public:
	Pensioner() : Adult() { cout << "конструктор по умолчанию Pensioner" << this << endl; }
	Pensioner(string name, string surname, int age) : Adult(name, surname, age) {
		cout << "конструктор с параметрами Pensioner" << this << endl;
	}
	
	void show() {
		cout << "--------Пенсионер--------" << endl;
		cout << "Имя: " << a_name << endl;
		cout << "Фамилия: " << a_surname << endl;
		cout << "Возраст: " << a_age << endl;
	}

	void setValues(string name, string surname, int age) {
		a_name = name;
		a_surname = surname;
		a_age = age;
	}

	void isWork(string job) {
		cout << "Получает пенсию и работает в компании \"" << job << '\"' << endl;
	}

	~Pensioner() { cout << "Деструктор Pensioner" << endl; }
};
