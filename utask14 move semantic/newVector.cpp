    /*
     * Реализовать собственную строку myStr/вектор myVec с поддержкой семантики перемещения. 
     * Предусмотреть возможность вывода сообщений о том, какой конструктор/деструктор вызывается.
     * Создать класс TextView/VectorView: закрытый член типа myStr/myVec+конструктор с одним константным параметром, 
     * инициализированным с использованием std::move(). Обратить внимание на влияние модификаторов объектов.
    */

#define _CRT_SECURE_NO_WARNINGS

#include "Vector.h"
#include "VectorView.h"
#include "Timer.h"
#include <chrono> 
#include <ctime>
#include <vector>

//размер задан не через v.size() для более корректного сравнения скоростей копирования и перемещения
Vector<int> cloneVector(const Vector<int>& v) {
    Vector<int> dbl(100);
    for (size_t i = 0; i < 100; i++) {
        dbl[i] = v[i];
    }
   //std::cout << v.size() << std::endl;
   //std::cout << dbl.size() << std::endl;
    return dbl;
}

int main() {
    setlocale(0, "");

    Vector<int> vec(100);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = i;
    }

    VectorView<int> vv(vec);
  
    Vector<int> vec2;
    Timer t;
    vec2 = cloneVector(vec);
    std::cout << t.elapsed() << std::endl;
   //std::cout << vec.size() << std::endl;


   //Vector<int> vecMove(std::move(vec));
   //vecMove = std::move(vec);
   //vec.show();
   //std::cout << vec.size() << std::endl;

    Timer w;
    Vector<int> vecMove2(vec);
    vecMove2 = vec;
    std::cout << w.elapsed() << std::endl;
}
