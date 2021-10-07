#include "ourClass.h"

MyString::MyString() {
    m_str = { 0 };
}

MyString::MyString(string str) {
	m_str = str;
}

MyString::~MyString() {}

string MyString::getStr() {
	return m_str;
}

void MyString::setStr(string str) {
	m_str = str;
}

void MyString::replace() {
    bool check = false;
    for (int i = 0; i < m_str.size(); i++) {
        if (m_str[i] == '!') {
            check = true;
            break;
        }
    }
    if (check == true) {
        for (int i = 0; i < m_str.size(); i++) {
            if (m_str[i] == '!') {
                m_str[i] = '?';
            }
        }
    } else {
        for (int i = 0, j = m_str.size() - 1; i < m_str.size() / 2; i++, j--) {
            swap(m_str[i], m_str[j]);
        }
    }
}

void MyString::replaceC() {
    bool check = false;
    for (int i = 0; i < m_str.size(); i++) {
        if (m_str[i] == 'c') {
            check = true;
            break;
        }
    }
    int count{ 0 };
    if (check == true) {
        for (int i = 0; i < m_str.size(); i++) {
            if (m_str[i] == 'c' || m_str[i] == 'C') {
                m_str[i] = m_str[0];
                count++;
            }
        } cout << endl << "Количество замен: " << count << endl;
    }
    else {
        cout << "Буквы С в строке нет." << endl;
    }
}

void MyString::multiplicity() {
    if (m_str.size() % 5 == 0) {
        m_str.erase(m_str.size() - (m_str.size()/5), (m_str.size() / 5));
    } else {
        char tmp = m_str[0];
        m_str[0] = m_str[m_str.size() - 1];
        m_str[m_str.size() - 1] = tmp;
    }
}
