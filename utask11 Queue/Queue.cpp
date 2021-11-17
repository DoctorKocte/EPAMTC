/*
Напишите шаблон класса для работы с очередью.
Программист не будет совершать ошибок при написании модели очереди. 
Например, вместимость очереди не будет превышена, 
а из пустой очереди не будет производиться попыток удаления данных.
Добавьте механизм обработки исключений в программу.
*/

#include <iostream>
#include "Queue.h"

int  main() {
    setlocale(0, "");
    Queue<int> Qq;
    std::cout << "getElem: " << Qq.getElem() << std::endl;
    Qq.pop();
    Qq.push(1);
    Qq.push(3);
    Qq.push(5);
    Qq.show();
    Qq.pop();
    Qq.show();
    std::cout << "getElem: " << Qq.getElem() << std::endl;
    //присваивание
    Queue<int> Que = Qq;
    Que.show();
    Que.push(7);
    //копирование
    Queue<int> Que2(Que);
    Que2.show();
    std::cout << "Que2.size(): " << Que2.size() << std::endl;
    Que2.clear();
    std::cout << "Que2.size() после clear(): " << Que2.size() << std::endl;
    std::cout << "Que2.show(): ";
    Que2.show();
}
