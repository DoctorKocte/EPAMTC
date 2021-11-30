#pragma once

#include <iostream>
#include <cassert>
#include <chrono> 
#include <ctime>

template <typename T> class Vector;
template <typename T> void setElem(Vector<T>& vect, int index, T const& elem);
template <typename T> T& getElem(Vector<T>& vect, int index);

template <typename T>
class Vector {
private:
    T* m_elem;
    size_t m_size;
public:
    class Iterator;
    Iterator begin() { return m_elem; }
    Iterator end() { return m_elem + m_size; }

    Vector() {
        std::cout << "Конструктор класса Вектор без параметров " << this << std::endl;
        m_elem = nullptr;
        m_size = 0;
    }
    Vector(int size) {
        std::cout << "Конструктор класса Вектор с параметром size " << this << std::endl;
        assert(size > 0);
        m_elem = new T[size];
        m_size = size;
    }


   // Vector(const Vector& p) = delete;
   //Конструктор перемещения
    Vector(Vector&& v) noexcept
        : m_size(v.m_size), m_elem(v.m_elem)
    {
        std::cout << "Вызван конструктор перемещением " << this << std::endl;
        v.m_size = 0;
        v.m_elem = nullptr;
    }


   //  Vector& operator= (const Vector& v) = delete;
   //  Оператор присваивания перемещением
    Vector& operator=(Vector&& v) noexcept {
        std::cout << "// Вызван оператор присваивания перемещением " << this << std::endl;
        if (&v == this) {
            return *this;
        }
        delete m_elem;

        m_size = v.m_size;
        m_elem = v.m_elem;
        v.m_size = 0;
        v.m_elem = nullptr;

        return *this;
    }


    Vector(const Vector& p)
        : m_size(p.m_size) 
    {
        std::cout << "Вызван конструктор копирования " << this << std::endl;
       // this->m_size = p.m_size;
        m_elem = new T[m_size];
        for (size_t i = 0; i < m_size; i++) {
            this->m_elem[i] = p.m_elem[i];
        }
    }

    Vector& operator = (const Vector& v) {
        std::cout << "//Вызван оператор присваивания копированием " << this << std::endl;
        if (&v == this) {
            return *this;
        }

        delete[] m_elem;

        m_size = v.m_size;
        m_elem = new T[m_size];

        for (size_t i = 0; i < m_size; ++i) {
            m_elem[i] = v.m_elem[i];
        }

        return *this;
    }

    ~Vector() {
        std::cout << "Вызван деструктор класса Вектор " << this << std::endl;
        delete m_elem;
        m_elem = nullptr;
        m_size = 0;
    }

    void show() const;
    size_t size() const;
    T& operator[](int index);
    const T& operator[](int index) const;
    void resize(size_t size);
    bool empty() const;
    void push_back(T newElem);
    void pop_back();
    void insert(size_t index, T newElem);
    T front() const;
    T back() const;
    void swap();
    void sort();
    void shellsort();
    T find(const T& el);
    friend T& getElem<T>(Vector<T>& vect, int x);
    friend void setElem<T>(Vector<T>& vect, int x, T const& data);

    class Iterator {
    private:
        T* cur;
    public:
        Iterator(T* first) : cur(first) {}
        T& operator+ (int offset) { return *(cur + offset); }
        T& operator- (int offset) { return *(cur - offset); }
        T& operator++ (int) { return *cur++; }
        T& operator-- (int) { return *cur--; }
        T& operator++ () { return *++cur; }
        T& operator-- () { return *--cur; }
        T& operator*() { return *cur; }
        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator== (const Iterator& it) { return cur == it.cur; }
        };
};


template<class InputIterator, class T>
InputIterator find_m(InputIterator first, InputIterator last, const T& val) {
    while (first != last) {
        if (*first == val) return first;
        ++first;
    }
    return last;
}

template <typename T>
T Vector<T>::find(const T& el) {
    for (T first = m_elem[0]; first < m_size; ++first) {
        if (first == el) {
            return first;
        }
    }
    return m_elem[m_size - 1];
}

template <typename T>
void Vector<T>::show() const {
    std::cout << "Вывод вектора: " << " [";
    for (size_t i = 0; i < m_size; i++) {
        std::cout << m_elem[i] << ", ";
    } std::cout << "\b\b]" << std::endl;
}

template <typename T>
void setElem(Vector<T>& v, int index, T const& elem) {
    v.m_elem[index] = elem;
}

template <typename T>
T& getElem(Vector<T>& vect, int index) {
    return vect.m_elem[index];
}


template <typename T>
T& Vector<T>::operator[] (int index) {
    return m_elem[index];
}

template <typename T>
const T& Vector<T>::operator[] (int index) const {
    return m_elem[index];
}


template <typename T>
size_t Vector<T>::size() const {
    return m_size;
}

template <typename T>
void Vector<T>::swap() {
    std::cout << "Вызван метод swap()" << "\n";
    for (size_t i = 0; i < m_size / 2; i++) {
        T temp = m_elem[i];
        m_elem[i] = m_elem[m_size - i - 1];
        m_elem[m_size - i - 1] = temp;
    }
}

template <typename T>
T Vector<T>::back() const {
    std::cout << "Вызван метод back()" << "\n";
    return m_elem[m_size - 1];
}

template <typename T>
T Vector<T>::front() const {
    std::cout << "Вызван метод front()" << "\n";
    return m_elem[0];
}

template <typename T>
void Vector<T>::insert(size_t index, T newElem) {
    std::cout << "Вызван метод insert() c параметрами " << index << " и " << newElem << "\n";
    assert(index >= 0 && index <= m_size);
    T* tmp = new T[m_size + 1];
    for (size_t i = 0; i < m_size + 1; i++) {
        if (i < index) {
            tmp[i] = m_elem[i];
        }
        if (i == index) {
            tmp[i] = newElem;
        }
        if (i > index) {
            tmp[i] = m_elem[i - 1];
        }
    }
    delete[] m_elem;
    m_elem = tmp;
    m_size += 1;
    tmp = nullptr;
    delete[] tmp;
}

template <typename T>
void Vector<T>::pop_back() {
    std::cout << "Вызван метод pop_back()" << "\n";
    T* tmp = new T[m_size - 1];
    if (m_size == 1) {
        delete[] m_elem;
        m_elem = tmp;
        m_size = 0;
    }
    else {
        for (size_t i = 0; i < m_size - 1; i++) {
            tmp[i] = m_elem[i];
        }
        delete[] m_elem;
        m_elem = tmp;
        tmp = nullptr;
        delete[] tmp;
        m_size -= 1;
    }
}

template <typename T>
void Vector<T>::push_back(T newElem) {
    std::cout << "Вызван метод push_back() c параметром " << newElem << "\n";
    T* tmp = new T[m_size + 1];
    for (size_t i = 0; i < m_size; i++) {
        tmp[i] = m_elem[i];
    }
    tmp[m_size] = newElem;
    delete[] m_elem;
    m_elem = tmp;
    tmp = nullptr;
    delete[] tmp;
    m_size += 1;
}

template <typename T>
bool Vector<T>::empty() const {
    return (m_size == 0);
}

template <typename T>
void Vector<T>::resize(size_t size) {
    std::cout << "Вызван метод resize() c параметром " << size << "\n";
    T* tmp = new T[size];
    if (size > m_size) {
        for (size_t i = 0; i < m_size; i++) {
            tmp[i] = m_elem[i];
        }
        for (size_t i = m_size; i < size; i++) {
            tmp[i] = 0;
        }
    }
    else {
        for (size_t i = 0; i < size; i++) {
            tmp[i] = m_elem[i];
        }
    }
    delete[] m_elem;
    m_elem = tmp;
    tmp = nullptr;
    delete[] tmp;
    m_size = size;
}


//модификация пузырька
template <typename T>
void Vector<T>::sort() {
    for (size_t i = 0; i < m_size; i++) {
        for (size_t j = m_size - 1; j > i; j--) {
            if (m_elem[i] > m_elem[j]) {
                //std::swap(m_elem[i], m_elem[j]);
                T temp = m_elem[i];
                m_elem[i] = m_elem[j];
                m_elem[j] = temp;
            }
        }
    }
}

template <typename T>
void Vector<T>::shellsort() {
    int tmp;
    size_t j;
    for (size_t step = m_size / 2; step > 0; step /= 2) {
        for (size_t i = step; i < m_size; i++) {
            tmp = m_elem[i];
            for (j = i; j >= step; j -= step) {
                if (tmp < m_elem[j - step]) {
                    m_elem[j] = m_elem[j - step];
                }
                else {
                    break;
                }
            }
            m_elem[j] = tmp;
        }
    }
}
