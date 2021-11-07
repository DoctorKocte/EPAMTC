/*
*
Определить комбинированный (структурный) тип, содержащий информацию о студенте: фамилия, имя, факультет, группа, e-mail.
Выделить статический массив памяти для 30 студентов.
Выделить динамический массив памяти для заранее неизвестного количества студентов.
Получить доступ к первому студенту из массива, используя разыменование указателя.
Вычислить размер памяти, занимаемый массивом студентов.
Проитерироваться по массиву студентов, используя инкремент указателя. Вывести в консоль адрес каждой структуры студента в памяти. Вывести сообщение о величине, на которую изменяется значение указателя при инкременте.
Вывести на консоль адреса соседних полей структуры.
Создать структуру с таким же набором полей, но другой последовательностью. Сравнить размеры структур. Вывести на консоль адреса каждого поля для обеих структур. Сделать выводы.
*
*/

#include <iostream>
#include <iomanip>

struct student {
	char surname[10];
	char name[10];
	char faculty[10];
	char group;
	char email[10];
};

struct studentTemp {
	char surname[10];
	char group;
	char email[10];
	char name[10];
	char faculty[10];
};

std::ostream& operator << (std::ostream& out, const student& p) {
	out << std::setw(10) << std::left << p.surname << std::setw(15) << std::left << p.name << std::setw(15) << std::left << p.faculty << std::setw(7) << p.group << p.email;
	return out;
}

std::istream& operator >> (std::istream& in, student& p) {
	std::cout << "Введите фамилию: ";
	in >> p.surname;
	std::cout << "Введите имя: ";
	in >> p.name;
	std::cout << "Введите факультет: ";
	in >> p.faculty;
	std::cout << "Введите группу: ";
	in >> p.group;
	std::cout << "Введите почту: ";
	in >> p.email;
	return in;
}

std::ostream& operator << (std::ostream& out, const studentTemp& p) {
	out << std::setw(10) << std::left << p.surname << std::setw(15) << std::left << p.group << std::setw(15) << std::left << p.email << std::setw(7) << p.name << p.faculty;
	return out;
}

std::istream& operator >> (std::istream& in, studentTemp& p) {
	std::cout << "Введите фамилию: ";
	in >> p.surname;
	std::cout << "Введите группу: ";
	in >> p.group;
	std::cout << "Введите почту: ";
	in >> p.email;
	std::cout << "Введите имя: ";
	in >> p.name;
	std::cout << "Введите факультет: ";
	in >> p.faculty;
	return in;
}

int main() {
	setlocale(0, "");
	student arr[2];
	for (int i = 0; i < 2; i++) {
		std::cin >> arr[i];
	}
	for (int i = 0; i < 2; i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << "Вывод адресов структур: " << std::endl;
	for (int i = 0; i < 2; i++) {
		std::cout << &arr[i] << std::endl;
	}
	std::cout << "Вывод адресов соседних элементов структуры: " << std::endl;
	std::cout << &arr[0].surname << std::endl;
	std::cout << &arr[0].name << std::endl;
	std::cout << &arr[0].faculty << std::endl;
	std::cout << (void*)&arr[0].group << std::endl;
	std::cout << &arr[0].email << std::endl;
	std::cout << "Вывод адресов соседних элементов структуры: " << std::endl;
	std::cout << &arr[1].surname << std::endl;
	std::cout << &arr[1].name << std::endl;
	std::cout << &arr[1].faculty << std::endl;
	std::cout << (void*)&arr[1].group << std::endl;
	std::cout << &arr[1].email << std::endl;

	std::cout << "Первый элемент массива: " << std::endl;
	std::cout << *arr << std::endl;
	std::cout << "Размер памяти, занимаемой массивом: " << std::endl;
	std::cout << sizeof(arr) << std::endl;//82

	char* p_a = (char*)(&arr[0].surname);
	char* p_b = (char*)(&arr[0].name);

	int differenceInBytes = (int)(p_b - p_a);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	p_a = (char*)(&arr[0].faculty);
	differenceInBytes = (p_a - p_b);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	p_b = (char*)(&arr[0].group);
	differenceInBytes = (p_b - p_a);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	p_a = (char*)(&arr[0].email);
	differenceInBytes = (p_a - p_b);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	p_b = (char*)(&arr[1].surname);
	differenceInBytes = (p_b - p_a);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	std::cout << "Вывод адресов структур при помощи указателя: " << std::endl;
	for (student* p = arr; p < arr + 2; ++p) {
		std::cout << p << std::endl;
	}

	int n;
	std::cout << "Введите кол-во студентов: ";
	std::cin >> n;
	student* d_arr = new student[n];
	std::cout << sizeof(*d_arr) << std::endl;//41

	studentTemp arrTemp[2];
	std::cout << sizeof(arrTemp) << std::endl;//82

	for (int i = 0; i < 2; i++) {
		std::cin >> arrTemp[i];
	}
	for (int i = 0; i < 2; i++) {
		std::cout << arrTemp[i] << std::endl;
	}
	std::cout << "Вывод адресов структур: " << std::endl;
	for (int i = 0; i < 2; i++) {
		std::cout << &arrTemp[i] << std::endl;
	}
	std::cout << "Вывод адресов соседних элементов структуры: " << std::endl;
	std::cout << &arrTemp[0].surname << std::endl;
	std::cout << (void*)&arrTemp[0].group << std::endl;
	std::cout << &arrTemp[0].email << std::endl;
	std::cout << &arrTemp[0].name << std::endl;
	std::cout << &arrTemp[0].faculty << std::endl;
	std::cout << "Вывод адресов соседних элементов структуры: " << std::endl;
	std::cout << &arrTemp[1].surname << std::endl;
	std::cout << (void*)&arrTemp[1].group << std::endl;
	std::cout << &arrTemp[1].email << std::endl;
	std::cout << &arrTemp[1].name << std::endl;
	std::cout << &arrTemp[1].faculty << std::endl;

	std::cout << "Первый элемент массива: " << std::endl;
	std::cout << *arrTemp << std::endl;
	std::cout << "Размер памяти, занимаемой массивом: " << std::endl;
	std::cout << sizeof(arrTemp) << std::endl;//82
	
	p_a = (char*)(&arrTemp[0].surname);
	p_b = (char*)(&arrTemp[0].group);

	differenceInBytes = (int)(p_b - p_a);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	p_a = (char*)(&arrTemp[0].email);
	differenceInBytes = (p_a - p_b);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	p_b = (char*)(&arrTemp[0].name);
	differenceInBytes = (p_b - p_a);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	p_a = (char*)(&arrTemp[0].faculty);
	differenceInBytes = (p_a - p_b);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	p_b = (char*)(&arrTemp[1].surname);
	differenceInBytes = (p_b - p_a);
	std::cout << "Вывод кол-ва байт для элемента структуры: " << differenceInBytes << std::endl;

	std::cout << "Вывод адресов структур при помощи указателя: " << std::endl;
	for (studentTemp* p2 = arrTemp; p2 < arrTemp + 2; ++p2) {
		std::cout << p2 << std::endl;
	}
}
