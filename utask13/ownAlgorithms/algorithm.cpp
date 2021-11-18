/*
 *  Пусть имеется контейнер, представляющий базу данных о покупателях: 
 *  фио, e-mail, количество покупок, сумма покупок.
 *  Необходимо определить всех наиболее частых покупателей 
 *  для создания списка рассылки для отправки рекламных материалов по почте. 
 *  Список рассылки не должен превышать 500 адресатов. 
 *  Необходимо удалить всех нечастых покупателей из нашей клиентской базы 
 *  и обновить записи по оставшимся частым покупателям для предоставления скидок. 
*/


#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <ctime>

struct customer {
	std::string secondname,		//фамилия
				firstname,		//имя
				patronymic,		//отчество
				email;			//почта
	unsigned int amount,		//количество покупок
					sum;		//сумма покупок
};

std::ostream& operator << (std::ostream& out, const customer& p) {
	out << std::setw(15) << std::left << p.secondname 
		<< std::setw(15) << std::left << p.firstname 
		<< std::setw(15) << std::left << p.patronymic 
		<< std::setw(15) << std::left << p.email 
		<< std::setw(15) << std::left << p.amount << p.sum;
	return out;
}

std::istream& operator >> (std::istream& in, customer& p) {
	in >> p.secondname;
	in >> p.firstname;
	in >> p.patronymic;
	in >> p.email;
	in >> p.amount;
	in >> p.sum;
	return in;
}

/*
	*	Функция генерации данных о посетителях
*/
const char* a[] = { "q", "w", "e" };
void gen(customer& p) {
	p.secondname = a[rand() % (sizeof a / sizeof(char*))]; // 12 / 4 unsigned int
	p.firstname = a[rand() % (sizeof a / sizeof(char*))];
	p.patronymic = a[rand() % (sizeof a / sizeof(char*))];
	p.email = p.secondname + p.firstname + p.patronymic + "@mail.ru";
	p.amount = rand() % (10 - 1 + 1) + 1;
	p.sum = rand() % (1000 - 100 + 1) + 100;
}

/*
	*	Предикат для поиска посетителей по ФИО (для тренировки в написании :) )
*/
struct find_predicate {
	std::string sname, fname, patr;
	find_predicate(std::string id, std::string id2, std::string id3) :sname(id), fname(id2), patr(id3) { }
	bool operator()(customer const& m) const {
		return m.secondname == sname && m.firstname == fname && m.patronymic == patr;
	}
};

/*
	*	Функция подсчета посещений магазина каждым посетителем
*/
int my_count_if(std::vector<customer>& vec, std::string const& surname, std::string const& name, std::string const& patron) {
	int count = 0;
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i].secondname == surname && vec[i].firstname == name && vec[i].patronymic == patron) {
			count++;
		}
	}
	return count;
}

/*
	*	Функция поиска посетителей, у которых кол-во посещений больше указанного num
*/
std::vector<std::string> my_find_if(std::map<std::string, int> const& mmap, int num) {
	std::cout << "find" << std::endl;
	std::vector<std::string> tmp;
	for (auto it = mmap.begin(); it != mmap.end(); ++it) {
		if ((*it).second > num)
			tmp.push_back((*it).first);
	}
	if (tmp.empty()) {
		std::cout << "Ни один посетитель не удовлетворяет условию. " << std::endl;
	}
	return tmp;
}

/*
	*	Функция удаления посетителей, у которых кол-во посещений меньше указанного num
*/
std::vector<std::string>  my_remove_if(std::map<std::string, int> const& mmap, int num) {
	std::cout << "remove" << std::endl;
	return my_find_if(mmap, num);
}

/*
	*	Функция поиска посетителей по указанному параметру val (при помощи итератора)
*/
template<typename InputIterator, typename T>
InputIterator my_find_iterator(InputIterator first, InputIterator last,  T& val) {
	std::cout << " my_find_iterator " << std::endl;
	while (first != last - 1) {
		if (*first == val) {
			return first;
		}
		++first;
	}
	return last - 1;
}

int main() {
	srand(time(0));
	setlocale(0, "");

	std::vector<customer> database(20);
	for (size_t i = 0; i < database.size(); i++) {
		//std::cin >> database[i];
		gen(database[i]);
	}

	std::cout << std::setw(15) << std::left << "Фамилия" 
		<< std::setw(15) << std::left << "Имя" 
		<< std::setw(15) << std::left << "Отчество" 
		<< std::setw(15) << std::left << "Почта" 
		<< std::setw(15) << std::left << "Кол-во покупок" << "Общая сумма" << std::endl;

	std::copy(database.begin(), database.end(), std::ostream_iterator<customer>(std::cout, "\n"));
	std::cout << std::endl;

	//	*	в visitors будем хранить частоту посещений посетителями магазина и данные о самих посетителях (имя, фамилия и отчество) без повторений
    //	*	ключ -- фамилия + имя + отчество, значение -- количество посещений магазина
	
	std::map<std::string, int> visitors;

	for (size_t i = 0; i < database.size(); i++) {
		std::string surname = database[i].secondname;
		std::string name = database[i].firstname;
		std::string patron = database[i].patronymic;

		//	*	с использованием стандартного алгоритма std::count_if
		//int nums = std::count_if(database.begin(), database.end(), find_predicate(surname, name, patron));
		//std::cout << "surname: " << surname << ", name " << name << ", count: " << nums << '\n';

		//	*	функция my_count_if(vector, arg1, arg2, arg3) осуществляет подсчет посещений магазина каждым посетителем
		//	*	где arg1, arg2, arg3 - поля структуры, по которым будет осуществляться поиск в векторе
		int nums = my_count_if(database, surname, name, patron);
		//можно без строк:		int nums = my_count_if(database, database[i].secondname, database[i].firstname, database[i].patronymic);

		std::string tmp = surname + " " + name + " " + patron;
		visitors.insert(make_pair(tmp, nums));
	}

	std::cout << "Количество уникальных посетителей в базе: " << visitors.size() << std::endl;


	std::cout << "Частота посещений магазина каждым посетителем: " << std::endl;
	for (auto it = visitors.begin(); it != visitors.end(); ++it) {
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}

	//	*	num -- количество посещений магазина, по которому посетителя относят к постоянным
	int num = 2 + rand() % 2;
	std::cout <<"Порог для попадания в список постоянных посетителей: " << num << std::endl;

	//	*	count для контроля количества посетителей в списке постоянных покупателей (не более 500)
	int count = 0;
	std::cout << "Список постоянных посетителей: " << std::endl;
	if (!visitors.empty()) {
		for (auto it = visitors.begin(); it != visitors.end(); ++it) {
			if ((*it).second > num) {
				std::cout << (*it).first << " : " << (*it).second << std::endl;
				count++;
				if (count == 500) {
					std::cout << "Список рассылки не может превышать 500 посетителей." << std::endl;
					break;
				}
			}
		}
	} else {
		std::cout << "Список пуст. Нет посетителей, удовлетворяющих условию." << std::endl;
	}
	//std::cout << count << std::endl;
	std::cout << std::endl;

	std::cout << "Список постоянных посетителей при помощи my_find_if: " << std::endl;
	std::vector<std::string> temp2;
	temp2 = my_find_if(visitors, num);
	if (temp2.size() < 500) {
		std::copy(temp2.begin(), temp2.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	} else {
		std::cout << "Список рассылки не может превышать 500 посетителей." << std::endl;
	} 	std::cout << std::endl;


	std::cout << "Список посетителей после удаления непостоянных клиентов функцией my_remove_if: " << std::endl;
	//	*	удаляем из списка всех непостоянных посетителей
	std::vector<std::string> temp;
	temp = my_remove_if(visitors, num);
	if (temp.size() < 500) {
		std::copy(temp.begin(), temp.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	} else {
		std::cout << "Список рассылки не может превышать 500 посетителей." << std::endl;
	}   std::cout << std::endl;


	std::cout << "Поиск по ФИО при помощи my_find_iterator: " << std::endl;
	if (!temp.empty()) {
		std::vector<std::string>::iterator its(temp.begin());
		std::string d = "q w w";
		//auto its = temp.begin();
		its = my_find_iterator(temp.begin(), temp.end(), d);
		if (its != (temp.end() - 1)) {
			std::cout << "Посетитель " << *its << " найден." << std::endl;
		} else {
			std::cout << "Посетитель " << d << " не найден." << std::endl;
		}
	} else {
		std::cout << "Вектор пуст, нет смысла проводить поиск." << std::endl;
	}
}
