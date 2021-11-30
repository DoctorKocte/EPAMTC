#pragma once
#include "Vector.h"

template <typename T>
class VectorView {
private:
	Vector<T> v;
public:
	VectorView(const Vector<T> vec) {
		std::cout << "Конструктор класса ВекторВью с параметром const Vector<T> vec " << this << std::endl;
		v = std::move(vec);
	}

	~VectorView() {
		std::cout << "Вызван деструктор класса ВекторВью " << this << std::endl;
	}
};
