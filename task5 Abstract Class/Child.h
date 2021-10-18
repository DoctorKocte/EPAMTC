#pragma once
#include "Man.h"

class Child : public IMan {
protected:
	string c_name;
	string c_surname;
	int c_age;

public:
	Child() {
		c_name = "";
		c_surname = "";
		c_age = 0;
		cout << "конструктор по умолчанию Adult" << this << endl;
	}

	Child(string name, string surname, int age) {
		c_name = name;
		c_surname = surname;
		c_age = age;
		cout << "конструктор с параметрами Child" << this << endl;
	}

	virtual void schoolOrGarten(int number) = 0;

	double costOfSections(double cost, ...) { //для передачи разного кол-ва параметров
			double result = 0;
			// получаем указатель на параметр cost
			for (double* ptr = &cost; cost > 0; cost--) {
				result += *(++ptr);
			}
			cout << "Расходы на секции: ";
			return result;
		}

	virtual ~Child() { cout << "destr child" << endl; }
};
