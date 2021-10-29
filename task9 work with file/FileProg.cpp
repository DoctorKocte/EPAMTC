//Сформировать массив, каждый элемент которого имеет следующую структуру служащий:
//ФИО, число рождения,  месяц рождения, год рождения, пол.


#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <boost/regex.h>
#include <boost\regex\v5\regex.hpp>
#include <boost\regex\v5\regex_match.hpp>

struct man {
	std::string secondname, 
				firstname, 
				patronymic, 
				gender, 
				month;
	unsigned short day,
				   year;
};

int menu();
std::vector<man> read_txt(std::vector<man>);
void output(std::vector<man>);
std::vector<man> sort(std::vector<man>);
std::vector<man> sort2(std::vector<man>);
std::vector<man> add(std::vector<man>);
void showMonth(std::vector<man>, std::string);
void showOldest(std::vector<man>);
void showSurnames(std::vector<man>, char);

//перегрузка оператора 
std::ostream& operator << (std::ostream& out, const man& p) {
	out << std::setw(10) << std::left << p.secondname << std::setw(15) << std::left <<  p.firstname << std::setw(15) << std::left <<  p.patronymic << std::setw(5) << std::left << p.day << std::setw(10) << std::left << p.month << std::setw(10) << std::left << p.year << p.gender;
	return out;
}

std::istream& operator >> (std::istream& in, man& p) {
	boost::regex expr{ "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?" };
	in >> p.secondname;
	bool alpha = boost::regex_match(p.secondname, expr) << '\n';
	if (alpha == true) {
		throw "Why did you enter numbers in secondname?";
	}
	in >> p.firstname;
	 alpha = boost::regex_match(p.firstname, expr) << '\n';
	if (alpha == true) {
		throw "Why did you enter numbers in firstname?";
	}
	in >> p.patronymic;
	 alpha = boost::regex_match(p.patronymic, expr) << '\n';
	if (alpha == true) {
		throw "Why did you enter numbers  in patronymic?";
	}
	in >> p.day;
	in >> p.month;
	 alpha = boost::regex_match(p.month, expr) << '\n';
	if (alpha == true) {
		throw "Please enter the name of the month but not number.";
	}
	in >> p.year;
	in >> p.gender;
	alpha = boost::regex_match(p.gender, expr) << '\n';
	if (alpha == true) {
		throw "Why did you enter numbers in gender?";
	}
	return in;
}

struct predicate {
	std::string elem;
	predicate(std::string p1) : elem(p1) {}
	bool operator ()(const man& p) {
		return (p.month == elem);
	}
};

struct predicate2 {
	std::string elem;
	predicate2(std::string p1) : elem(p1) {}
	bool operator ()(const man& p) {
		return p.gender == elem;
	}
};

struct predicate3 {
	char elem;
	predicate3(char p1) : elem(p1) {}
	bool operator ()(const man& p) {
		return p.secondname[0] == elem;
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		menu();
	}
	catch (const char* exception) 
	{
		std::cout << "Error: " << exception << std::endl;
	}
	return 0;
}

int menu() {
	int choice;
	std::vector<man> v;
	std::string temp;
	char tmp;
	do {
		std::cout << "Меню: " << std::endl;
		std::cout << "1) Чтение данных из файла." << std::endl;
		std::cout << "2) Вывод данных." << std::endl;
		std::cout << "3) Сортировка по возрасту." << std::endl;
		std::cout << "4) Сортировка по алфавиту." << std::endl;
		std::cout << "5) Добавление данных." << std::endl;
		std::cout << "6) Вывод: список людей, родившихся в заданном месяце." << std::endl;
		std::cout << "7) Вывод: фамилию самого старшего мужчины." << std::endl;
		std::cout << "8) Вывод: все фамилии, начинающиеся с заданной буквы." << std::endl;
		std::cout << "0) Выход. " << std::endl;
		std::cout << std::endl;

		std::cout << "Ваше действие: ";
		std::cin >> choice;
		std::cout << std::endl;
		system("cls");

		switch (choice) {
		case 1:
			v = read_txt(v);
			std::cin.ignore();
			break;
		case 2:
			std::cout << "Вывод данных: " << std::endl;
			output(v);
			break;
		case 3:
			std::cout << "Сортировка по возрасту: " << std::endl;
			v = sort(v);
			output(v);
			break;
		case 4:
			std::cout << "Сортировка по алфавиту: " << std::endl;
			v = sort2(v);
			output(v);
			break;
		case 5:
			std::cin.ignore();
			v = add(v);
			break;
		case 6:
			std::cin.ignore();
			std::cout << "Введите месяц(на английском): ";
			std::cin >> temp;
			showMonth(v, temp);
			std::cin.ignore();
			break;
		case 7:
			std::cout << "Фамилия самого старшего мужчины: " << std::endl;
			showOldest(v);
			std::cin.ignore();
			break;
		case 8:
			std::cout << "Все фамилии с заданной буквы: " << std::endl;
			std::cout << "Введите букву(на английском): ";
			std::cin >> tmp;
			showSurnames(v, tmp);
			std::cin.ignore();
			break;
		}
		std::cin.ignore();
		system("cls");
	} while (choice != 0);
	return 0;
}

std::vector<man> read_txt(std::vector<man> v) {
	//проверка ввода
	std::ifstream fin("file.txt");
	std::ofstream fout("output.txt");
	if (!fin.is_open()) {
		std::cout << "Не удалось открыть файл для чтения данных." << std::endl;
	}
	else if (fin.peek() == EOF) {
		std::cout << "Файл пустой." << std::endl; // если первый символ конец файла
	}
	if (!fout.is_open()) {
		std::cout << "Не удалось открыть файл для записи данных." << std::endl;
	}
	std::copy(std::istream_iterator<man>(fin), std::istream_iterator<man>(), std::inserter(v, v.end()));
	std::copy(v.begin(), v.end(), std::ostream_iterator<man>(fout, "\n"));
	std::cout << "Данные считаны из файла." << std::endl;
	fin.close();
	fout.close();
	return v;
}

void output(std::vector<man> v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<man>(std::cout, "\n"));
	std::cin.ignore();
}
bool comparator(const man& p1, const man& p2) {
	return p1.year < p2.year;
}

std::vector<man> sort(std::vector<man> v) {
	std::sort(v.begin(), v.end(), comparator);
	return v;
}

bool comparator2(const man& p1, const man& p2) {
	return p1.secondname < p2.secondname;
}

std::vector<man> sort2(std::vector<man> v) {
	std::sort(v.begin(), v.end(), comparator2);
	return v;
}

std::vector<man> add(std::vector<man> v) {
	std::cout << "Введите данные о работнике(ФИО, день рождения, месяц, год и пол): " << std::endl;
	std::vector<man> vect;
	std::copy(v.begin(), v.end(), std::back_inserter(vect));
	vect.resize(vect.size() + 1);
	std::cin >> vect[v.size()];
	std::ofstream fout("output.txt");
	if (!fout.is_open()) {
		std::cout << "Не удалось открыть файл для записи данных." << std::endl;
	}
	std::copy(vect.begin(), vect.end(), std::ostream_iterator<man>(fout, "\n"));
	return vect;
}

void showMonth(std::vector<man> v, std::string monthValue) {
	std::copy_if(v.begin(), v.end(), std::ostream_iterator<man>(std::cout, "\n"), predicate(monthValue));
}

void showOldest(std::vector<man> v) {
	std::vector<man> c(v);
	std::vector<man> b;
	c = sort(c);
	std::copy_if(c.begin(), c.end(), std::back_inserter(b), predicate2("male"));
	std::cout << b[0];
}

void showSurnames(std::vector<man> v, char character) {
	std::copy_if(v.begin(), v.end(), std::ostream_iterator<man>(std::cout, "\n"), predicate3(character));
}
