#include <iostream>
#include <Windows.h>
#include "ourClass.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Дана строка символов. Если в ней есть символ !, то заменить все символы ! на ? , иначе изменить порядок следования символов на обратный." << endl;
    string temp;
    cout << "Введите строку:  ";
    cin >> temp;
    //MyString str; //для проверки конструктора по умолчанию
    // str = temp;
    //cout << endl << "mtcm " << str.getStr();
    MyString st(temp);
    st.replace();
    cout << "Новая строка: " << st.getStr() << endl;
   
    cout << endl << "Дана строка символов. Заменить в ней каждую букву C на первую букву последовательности, подсчитать количество таких замен." << endl;
    st.setStr("Aaa cCc erjn 11vc qc");
    cout << endl << "Заменяем строку на: " << st.getStr();
    st.replaceC();
    cout << "Новая строка: " << st.getStr() << endl;
    
    cout << endl << "Дана строка символов. Если длина строки кратна 5, удалить последнюю 1/5 длины строки, в противном случае поменять местами первый и последний символы строки." << endl;
    cout << endl << "Строка до удаления: " << st.getStr() << endl;
    st.multiplicity();
    cout << "Новая строка: " << st.getStr() << endl;

    cout << endl << "Строка до замены: " << st.getStr() << endl;
    st.multiplicity();
    cout << "Новая строка: " << st.getStr() << endl;
}
