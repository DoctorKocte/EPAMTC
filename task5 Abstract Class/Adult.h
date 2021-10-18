#pragma once
#include "Man.h"

class Adult : public IMan {
protected:
	//поля можно было сделать и в классе Man (и он бы уже не был интерфейсом), 
	//но по заданию "Базовый класс 1 уровня – абстрактный, содержащий чисто виртуальные функции. 
	//Классы 2 уровня – абстрактные, содержащие поля  и тд"
	string a_name;
	string a_surname;
	int a_age;

public:
	Adult() {
		a_name = "";
		a_surname = "";
		a_age = 0;
		cout << "конструктор по умолчанию Adult" << this << endl;
	}

	Adult(string name, string surname, int age) {
		a_name = name;
		a_surname = surname;
		a_age = age;
		cout << "конструктор с параметрами Adult" << this << endl;

	}
	
	//функция для установки работы взрослого\пенсионера
	virtual void isWork(string job) = 0;

	double averageIncome(double income) {
		double avIncome = income / 12;
		cout << "Средний доход: "; 
		return avIncome;
	}

	//деструктор лучше делать виртуальным, так как при создании объекта, 
	//например, 
	//Adult* tmp = new Employee("sss", "ccc", 34);
	//delete tmp;
	//будет вызван только деструктор базового класса и память, выделенная под производный класс, благополучно потеряется

	virtual ~Adult() { cout << "destr adult" << endl; }
};
