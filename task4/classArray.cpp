#include <iostream>
#include <Windows.h>
#include "Array.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Array<int> mas;
	mas.show();
	cout << "Найти произведение отрицательных элементов, расположенных ниже главной диагонали." << endl;
	Array<int> array(3, 2);
	array.show();
	sum2(array);
	Array<char> arr(2, 2);
	arr.show();
	Array<int> arr2(array);
	arr2.show();
}
