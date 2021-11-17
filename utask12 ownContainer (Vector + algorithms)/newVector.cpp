#define _CRT_SECURE_NO_WARNINGS

#include "Vector.h"
#include <chrono> 
#include <ctime>
#include <vector>
#include <algorithm>

template <typename T>
void findtime(Vector<T> vec);
template <typename T>
void findtime2(std::vector<T> vec);
template <typename T>
void findtime3(Vector<T> vec);
template <typename T>
void sorttime(Vector<T> vec);
template <typename T>
void sorttime2(Vector<T> vec);

int main() {
    setlocale(0,"");
    Vector <int> vec(3);
    for (int i = 0; i < 3; i++) {
        vec[i] = i+1;
    }
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "Вектор из " << vec.size() << " элементов: ";
    vec.show();
    std::cout << "Длина вектора: " << vec.size() << std::endl;
    vec.resize(5);
    vec.show();
    std::cout << "Длина вектора: " << vec.size() << std::endl;
    vec.resize(4);
    vec.show();
    std::cout << "Длина вектора: " << vec.size() << std::endl;
    vec.push_back(4);
    vec.push_back(5);
    vec.show();
    vec.pop_back();
    vec.show();
    std::cout << vec.front() << std::endl;
    std::cout << vec.back() << std::endl;
    vec.insert(1, 30);
    vec.show();
    vec.swap();
    vec.show();
    if (vec.empty() == 1) {
        std::cout << "В векторе нет элементов." << std::endl;
    }
    else {
        std::cout << "Вектор содержит элементы." << std::endl;
    }
    std::cout << "Вывод векора с помощью функции getElem(): " << std::endl;
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << getElem(vec, i) << " ";
    } std::cout << std::endl;
    setElem(vec, 3, 1);
    vec.show();

    auto it = Vector<int>::Iterator(vec.begin());
    std::cout << "Вывод вектора при помощи итератора:" << std::endl;
    while (it != vec.end()) {
        std::cout << *it << " ";
        it++;
    } std::cout << std::endl;

   /* Vector<int> vec(1000);
    std::vector<int> vec2(1000);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % 100;
    }
    for (int i = 0; i < vec2.size(); i++) {
        vec2[i] = rand() % 100;
    }

    findtime2(vec2);
    findtime(vec);
    findtime3(vec);

    Vector<int> vec3(vec);
    sorttime(vec);
    sorttime2(vec3);*/
}

template <typename T>
void findtime(Vector<T> vec) {
    std::cout << "Поиск элемента в class Vector при помощи find." << std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    vec.find(3);

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

template <typename T>
void findtime2(std::vector<T> vec) {
    std::cout << "Поиск элемента в std::vector при помощи std::find." << std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    std::find(vec.begin(), vec.end(), 3);

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

template <typename T>
void findtime3(Vector<T> vec) {
    std::cout << "Поиск элемента в class Vector при помощи find_m(vec.begin(), vec.end(), value);." << std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    find_m(vec.begin(), vec.end(), 3);

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

template <typename T>
void sorttime(Vector<T> vec) {
    std::cout << "Сортировка пузырьком." << std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    vec.sort();

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}


template <typename T>
void sorttime2(Vector<T> vec) {
    std::cout << "Сортировка Шелла." << std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    vec.shellsort();

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
