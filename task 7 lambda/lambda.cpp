#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//#include <cassert>

int main() {
	setlocale(0, "");
	std::vector<int> vect{ 1,3,2,6,5 };

	//Создать лямбда-выражение для вывода элементов вектора.
	std::cout << "Вывод вектора: ";
	std::for_each(vect.begin(), vect.end(), [](int number)
		{
			std::cout << number << " ";
		});
	std::cout << std::endl;

	//Создать лямбда-выражение для подсчета количества перестановок при выполнении сортировки элементов вектора
	int comparisons{ 0 };
	sort(vect.begin(), vect.end(), [&comparisons](auto& a, auto& b) 
														{
														if (a < b) {
															comparisons++;
														}
														return (a < b);
														});

	std::cout << "Количество сравнений: " << comparisons << std::endl;
	std::cout << "Отсортироавнный вектор: ";
	std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	//Создать лямбда-выражение для поиска вхождения подстроки, задаваемой пользователем, в строку.
	std::vector<std::string> vct{ "apple", "banana", "walnut", "lemon" };
	std::string st;
	std::cout << "Введите подстроку: ";
	std::cin >> st;
	auto found{ std::find_if(vct.begin(), vct.end(),
							 [st](std::string str)
							 {
								return (str.find(st) != std::string::npos);
							 }) };
	if (found == vct.end()) {
		std::cout << "Ничего не найдено." << std::endl;
	} else {
		std::cout << "Найдено " << *found << std::endl;
	}


	//Выполнить генерацию вектора из Nпоследовательных элементов (например, 0 1 2 3 4)
	std::vector<int> vt(5);
	
	int num{ 0 };
	for (size_t i = 0; i < vt.size(); i++) {
		vt[i] = [&num]() {
						 num++;
						 return num;
						 }();
	}
	std::cout << "Сгенерированный вектор: ";
	std::copy(vt.begin(), vt.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//Сформировать новый вектор по следующему правилу: отбросить слева k первых элементов 
	//и добавить k последовательных элементов в конец вектора (например, k=2, новый вектор 2 3 4 5 6)
	unsigned short tmp;
	std::cout << "Введите k: ";
	std::cin >> tmp;
	//assert(tmp >= 0);

	std::vector<int> tmpVect(vt.size());
	//лучше перезаписать в новый вектор
	int g{ 0 };
	for (size_t i = tmp; i < vt.size(); i++) {
		tmpVect[g] = vt[i];
		g++;
	}

	for (size_t i = tmpVect.size() - tmp; i < tmpVect.size(); i++) {
		tmpVect[i] = [&num]() {
						 num++;
						 return num;
						 }();
	}

	std::cout << "Новый вектор: ";
	std::copy(tmpVect.begin(), tmpVect.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
