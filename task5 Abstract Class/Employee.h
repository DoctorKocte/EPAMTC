#pragma once
#include "Adult.h"

class Employee : public Adult {
public:
	Employee() : Adult() { cout << "конструктор по умолчанию Employee" << this << endl; }
	Employee(string name, string surname, int age) : Adult(name, surname, age) {
		cout << "конструктор с параметрами Employee" << this << endl;
	}
	
	void show() {
		cout << "--------Работающий--------" << endl;
		cout << "Имя: " << a_name << endl;
		cout << "Фамилия: " << a_surname << endl;
		cout << "Возраст: " << a_age << endl;
	}

	void isWork(string job) {
		cout << "Работает в компании \"" << job << '\"' << endl;
	}

	~Employee() { cout << "Деструктор Employee" << endl; }
};
