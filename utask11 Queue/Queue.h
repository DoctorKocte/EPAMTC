#pragma once
#include <iostream>

template <typename T>
class Queue {
private:
    T* m_que;
    size_t m_size;
public:
    Queue() {
        m_size = 0;
        m_que = nullptr;
    }

    Queue(const Queue& obj) {
        m_size = obj.m_size;
        try {
            m_que = new T[m_size];
            for (size_t i = 0; i < m_size; i++) {
                m_que[i] = obj.m_que[i];
            }
        }
        catch (std::bad_alloc ex) {
            std::cout << ex.what() << std::endl;
            m_size = 0;
        }
    }

    Queue& operator=(const Queue& obj) {
        try {
            T* tmp = new T[obj.m_size];
            if (m_size > 0) {
                m_que = nullptr;
                delete[] m_que;
            }
            m_que = tmp;
            m_size = obj.m_size;
            for (size_t i = 0; i < m_size; i++) {
                m_que[i] = obj.m_que[i];
            }
            tmp = nullptr;
            delete[] tmp;
        }
        catch (std::bad_alloc ex) {
            std::cout << ex.what() << std::endl;
        }
        return *this; // вернуть текущий объект
    }

    ~Queue() {
        m_que = nullptr;
        delete[] m_que;
        m_size = 0;
    }

    void push(T elem);
    T pop();
    T getElem() const; //функция получения элемента
    void clear();
    bool empty() const;
    int size() const;
    void show() const;
};

template <typename T>
void Queue<T>::push(T elem) {
    T* tmp = new T[m_size + 1];
    try {
        for (size_t i = 0; i < m_size; i++) {
            tmp[i] = m_que[i];
        }
        tmp[m_size] = elem;
        delete[] m_que;
        m_que = tmp;
        m_size++;
        tmp = nullptr;
        delete[] tmp;
    }
    catch (std::bad_alloc ex) {
        std::cout << ex.what() << std::endl;
        m_que = tmp;
        tmp = nullptr;
        delete[] tmp;
    }
}

template <typename T>
T Queue<T>::pop() {
    try {
        if (m_size == 0) {
            throw 1;
        }
        T elem = m_que[0];
        T* tmp = new T[m_size - 1];
        m_size--;
        for (size_t i = 0; i < m_size; i++) {
            tmp[i] = m_que[i + 1];
        }
        m_que = nullptr;
        delete[] m_que;
        m_que = tmp;
        tmp = nullptr;
        delete[] tmp;
        return elem;
    }
    catch (int) {
        std::cout << "Нельзя извлечь элемент из пустой очереди." << std::endl;
        return 0;
    }
    catch (std::bad_alloc ex) {
        std::cout << ex.what() << std::endl;
        return 0;
    }
}

template <typename T>
T Queue<T>::getElem() const {
    if (m_size > 0) {
        return m_que[0];
    }
    else {
        std::cout << "Очередь пуста, нельзя получить элемент." << std::endl;
        return 0;
    }
}

template <typename T>
void  Queue<T>::clear() {
    if (m_size > 0) {
        m_que = nullptr;
        delete[] m_que;
        m_size = 0;
    }
}

template <typename T>
bool  Queue<T>::empty() const {
    return (m_size == 0);
}

template <typename T>
int  Queue<T>::size() const {
    return m_size;
}

template <typename T>
void  Queue<T>::show() const {
    if (m_size > 0) {
        std::cout << "Вывод очереди: " << " [";
        for (size_t i = 0; i < m_size; i++) {
            std::cout << m_que[i] << ", ";
        } std::cout << "\b\b]" << std::endl;
    }
    else {
        std::cout << "Очередь пуста" << std::endl;
    }
}
