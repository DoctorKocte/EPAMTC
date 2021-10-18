#pragma once
#include "Child.h"

class Schoolkid : public Child {
public:
	Schoolkid() : Child() { cout << "конструктор по умолчанию Schoolkid" << this << endl;  }
	Schoolkid(string name, string surname, int age) : Child(name, surname, age) {
	  cout << "конструктор с параметрами Schoolkid" << this << endl;
	}

	void show() {
		cout << "--------Школьник--------" << endl;
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
		cout << "Школа №" << number << endl;
	}

	~Schoolkid() { cout << "Деструктор Schoolkid" << endl; }
};
