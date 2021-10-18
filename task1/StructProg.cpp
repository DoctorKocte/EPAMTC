#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

void output(struct student*, int); //функция вывода данных
int getMarksSum(struct student); //функция подсчета суммарного балла студента

struct student {
    string secondName;
    string Name;
    int marks[3];
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введите количество студентов: ";
    cin >> N;
    student* masSt = new student[N];

    //ввод данных о студенте
    for (int i = 0; i < N; i++) {
        cout << "Введите фамилию студента: ";
        cin >> masSt[i].secondName;
        cout << "Введите имя студента: ";
        cin >> masSt[i].Name;
        cout << "Введите три отметки студента через пробел: ";
        for (int j = 0; j < 3; j++) {
            cin >> masSt[i].marks[j];
        } cout << endl;
    }
    output(masSt, N);

    //создаем временную переменную и сортируем массив структур 
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            //при работе с большими данными лучше обойтись без подобного вызова функций
            if (getMarksSum(masSt[j]) < getMarksSum(masSt[j + 1])) {
                student tmp = masSt[j];
                masSt[j] = masSt[j + 1];
                masSt[j + 1] = tmp;
            }
        }
    }
    cout << "Сортировка по убыванию по сумме баллов:" << endl;
    output(masSt, N);

    //очищаем память
    delete[] masSt;
}


void output(student* masSt, int N) {
    cout << setw(20) << left << "Фамилия" << setw(20) << left << "Имя" << "Оценки" << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(20) << left << masSt[i].secondName << setw(20) << left << masSt[i].Name;
        for (int j = 0; j < 3; j++) {
            cout << masSt[i].marks[j] << "; ";
        } cout << endl;
    }  
}

int getMarksSum(student masSt) {
    return masSt.marks[0] + masSt.marks[1] + masSt.marks[2];
}
