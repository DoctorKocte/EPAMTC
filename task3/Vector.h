#pragma once
#include <iostream>

template <typename T>
class Vect {
private:
	T* m_elem;
	int m_size;
public:

	Vect() {
		m_elem = 0;
		m_size = 0;
	}

	Vect(const Vect& p) { //конструктор копирования
		this->m_size = p.m_size;
		m_elem = new T[m_size];
		for (int i = 0; i < m_size; i++) {
			this->m_elem[i] = p.m_elem[i];
		}
	}

	Vect(int size) {
		m_size = size;
		m_elem = new T[size];
	}

	int size() {
		return m_size;
	}

	void input() {
		std::cout << "Введите " << m_size << " элементов: ";
		for (int i = 0; i < m_size; i++) {
			std::cin >> m_elem[i];
		}
	}

	void show() {
		std::cout << "Вывод вектора: " << this << " [";
		for (int i = 0; i < m_size; i++) {
			std::cout << this->m_elem[i] << ", ";
		} std::cout << "\b\b]" << std::endl;
	}

	void sort() {
		//int temp = 0;
		for (int i = 0; i < m_size; i++) {
			for (int j = i; j < m_size; j++)
				if (m_elem[i] > m_elem[j]) {
					std::swap(m_elem[i], m_elem[j]);
					//temp = m_elem[j];
					//m_elem[j] = m_elem[i];
					//m_elem[i] = temp;
				}
		}
	}

	T max()
	{
		sort();
		return m_elem[m_size - 1];
	}

	T min()
	{
		sort();
		return m_elem[0];
	}
	T average()
	{
		sort();
		return m_elem[m_size / 2];
	}

	void changePosition() {
		T* temp = new T[m_size];
		for (int i = 0; i < m_size; i++) {
			temp[i] = m_elem[i];
		}

		/*int j = 0;
		for (int i = 0; i < m_size; i++) {
			if (i % 2 == 1) {
				m_elem[j] = temp[i];
				j++;
			}
		}
		j = m_size / 2;
		for (int i = 0; i < m_size; i++) {
			if (i % 2 == 0) {
				m_elem[j] = temp[i];
				j++;
			}
		}*/

		for (int i = 0, j = 1; i < m_size / 2, j < m_size; i++, j+=2) {
				m_elem[i] = temp[j];
		}
		for (int i = m_size / 2, j = 0; i < m_size, j < m_size; i++, j += 2) {
			m_elem[i] = temp[j];
		}
		
	}

	~Vect() {
		delete[] m_elem;
	//	std::cout << this << std::endl;
	}
};
