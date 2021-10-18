#pragma once
#include "Child.h"

class Preschooler : public Child {
public:
	Preschooler() : Child() { cout << "конструктор по умолчанию Preschooler" << this << endl;  }
	Preschooler(string name, string surname, int age) : Child(name, surname, age) {
		cout << "конструктор с параметрами Preschooler" << this << endl;
	}
  
	void show() {
		cout << "--------Дошкольник--------" << endl;
		cout << "Имя: " << c_name << endl;
		cout << "Фамилия: " << c_surname << endl;
		cout << "Возраст: " << c_age << endl;
	}

	void setValues(string name, string surname, int age) {
		c_name = name;
		c_surname = surname;
		c_age = age;
	}

	void schoolOrGarten(int number) {
		cout << "Детский сад №" << number << endl;
	}

	~Preschooler() { cout << "Деструктор Preschooler" << endl; }
};
