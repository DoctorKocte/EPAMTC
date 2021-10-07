#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <typename T> class Array;
//template <typename T> void sum(Array<T>& var);
template <typename T> void sum2(Array<T>& var);

template <typename T>
class Array {
private:
	T** arr;
	int a;
	int b;
public:
	//конструктор по умолчанию
	Array() {
		cout << "Введите кол-во строк: ";
		cin >> a;
		cout << "Введите кол-во столбцов: ";
		cin >> b;
		arr = new T* [a];
		for (int i = 0; i < a; i++) {
			arr[i] = new T[b];
		}
		cout << "Введите " << a * b << " элемента/ов: ";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> arr[i][j];
			}
		}
	}
	//конструктор с параметрами
	Array(int a, int b) {
		this->a = a;
		this->b = b;
		arr = new T*[a];
		for (int i = 0; i < a; i++) {
			arr[i] = new T[b];
		}
		cout << "Введите " << a*b << " элемента/ов: ";
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> arr[i][j];
			}
		}
	}
	//коструктор копирвоания
	Array(const Array& p) { //конструктор копирования
		this->a = p.a;
		this->b = p.b;
		arr = new T*[a];
		for (int i = 0; i < a; i++) {
			arr[i] = new T[b];
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				this->arr[i][j] = p.arr[i][j];
			}
		}
	}
	//деструктор
	~Array() {
		for (int i = 0; i < a; i++) {
			delete arr[i];
		}
		delete[] arr;
	}

	void show() {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cout << arr[i][j] << '\t';
			} cout << endl;
		} cout << endl;
	}

	//friend void sum<T>(Array<T>& obj);
	friend void sum2<T>(Array<T>& obj);

};

//доработать
//template <typename T>
//void sum(Array<T>& obj) {
//	for (int i = 0; i < obj.a; i++) {
//		for (int j = 0; j < obj.b; j++) {
//			if (obj.arr[j][i] > 0) {
//			
//				for (int k = 0; k < obj.b; k++) {
//					T sum = 0;
//					for (int g = 0; g < obj.a; g++) {
//						sum += obj.arr[g][k];
//					} cout << "Сумма столбика " << i + 1 << ": " << sum << endl;
//					
//				} 
//				break;
//			}
//			
//		}
//	}
//}

template <typename T>
void sum2(Array<T>& obj) {
	T mult = 1;
	bool check = false;
	for (int i = 0; i < obj.a; i++) {
		for (int j = 0; j < i; j++) {
			if ((obj.arr[i][j] < 0)) {
				check = true;
				mult = mult * obj.arr[i][j];
			}
		} 
	} 
	if (check == true) {
		cout << "Произведение отрицательных чисел, находящихся ниже главной диагонали: " << mult << endl;
	} else {
		cout << "В массиве нет отрицательных чисел." << endl;
	}
}
