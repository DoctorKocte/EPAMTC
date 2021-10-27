#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

/* 
    Задача о рюкзаке является NP-полной задачей, то есть для ее решения не существует полиномиального алгоритма.
    Полиномиальный алгоритм - алгоритм, время которого не слишком сильно зависит от размера входных данных.
    Задача решена методом динамического программирования(ДП). 
    Вычислительная сложность данного метода - O(nW), где n - количество предметов, W - заданная вместимость.
    В основе метода ДП лежит принцип оптимальноти Беллмана: 
    оптимальное решение на i-ом шаге находится исходя из найденных оптимальных решений на предшествующих шагах.
    ДП - псевдополиномиальный алгоритм (алгоритм, проявляющий экспоненциальный характер при очень больших значениях числовых параметров).
    Эффективность данного алгоритма определяется значением W. 
    Алгоритм даёт отличные результаты при W <= 1000, но не очень хорошие для W >= 10 000 000.
*/

std::string knapSack(int W, std::vector<int> weight, std::vector<int> value, std::vector<std::string> things) {
    int n = value.size(); //4

    std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1));
    std::string str = "";
    int a, b;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) { //пустые ячейки
                K[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                //если вес вещи меньше размера рюкзака
                //выбираем, что больше: ценность данной вещи + ценность предыдущих вещей (которые смогут поместиться вместе с новой вещью)
                //ИЛИ предыдущее значение ценностей 
                //[w - weigth[i - 1]] - от вместимости отнимаем вес данной вещи, чтобы попасть в ячейку с вещью\вещами, котооые мы еще можем добавить

                a = value[i - 1] + K[i - 1][w - weight[i - 1]];
                b = K[i - 1][w];

                K[i][w] = std::max(a, b);
                int h = 0;
                if (a > b) {
                    int  tmp = value[i - 1];
                    int tmp2 = K[i - 1][w - weight[i - 1]];
                    for (int j = 0; j < n; j++) {
                        if (tmp2 == value[j]) {
                            h = j;
                        }
                    }
                    str = things[i - 1];
                    str += " и ";
                    str += things[h];
                }
            } else { //если вес текущей вещи больше размера рюкзака, то берем предыдущую вещь
                K[i][w] = K[i - 1][w];
            }
        }
    } std::cout << std::endl << std::endl;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            std::cout <<  K[i][w] << "\t";
        } std::cout << std::endl;
    }
    return str;
}

int main() {
    setlocale(0, "");
    std::cout << "Задание 1. Заполнить вектор v2 содержимым второй половины вектора v1." << std::endl;
    std::vector<int> v1{ 1,2,3,4,5,6 };
    std::vector<int> v2;
    v2.assign(v1.begin() + v1.size() / 2, v1.end());
    std::cout << "Вектор v1: ";
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nВектор v2: ";
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));


    std::cout << "\n\nЗадание 2. Задача о рюкзаке. Она состоит в том, чтобы выбрать, какие предметы," 
        <<" имеющие вес и стоимость, поместить в рюкзак ограниченной ёмкости W, да так, чтобы максимизировать общую ценность его содержимого.\n";
    std::vector<std::string> things{ "Кольцо", "Ожерелье", "Кулон", "Перстень" };
    std::vector<int> value{ 60, 100, 120, 140 };
    std::vector<int> weight{ 1, 2, 3, 4 };
    int W = 5; //вместимость

    std::cout << std::setw(10) << std::left << "Вещь: " << std::setw(10) << std::left << "Вес: " << "Стоимость:\n";
    for (int i = 0; i < value.size(); i++) {
        std::cout << std::setw(10) << std::left << things[i] << std::setw(10) << std::left 
            << weight[i] << std::setw(10) << std::left << value[i] << std::endl;
    }

    //Так как мы используем вектор, можно не передавать их размерность 
    std::cout << "\nВещи, которые мы возьмем: " << knapSack(W, weight, value, things) << std::endl;
}
