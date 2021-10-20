#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

template <typename T, typename V>
class Conversion {
private:
	T m_currency;
	V m_amount;
public:
	Conversion() {
		m_currency = 0;
		m_amount = 0;
	}

	Conversion(T currency, V amount) {
		m_currency = currency;
		m_amount = amount;
	}

	void sum(Conversion<T, V> obj);

	~Conversion(){}
};

template <typename T, typename V>
void Conversion<T,V>::sum(Conversion<T, V> obj) {
	double byn1 = m_amount * m_currency;
	double byn2 = obj.m_amount * obj.m_currency;
	double sum = byn1 + byn2;
	cout << sum << endl;
}
