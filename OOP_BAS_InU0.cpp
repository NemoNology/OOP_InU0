#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


// Пространство имён VecFun - Vector's Functions
namespace VecFun { 

    // Функция вывода 1D вектора
    void Show_1D_Vector(const vector<int>& vec) {

        cout << "\n\n"; cout << setw(8);
        for (unsigned i = 0; i < vec.size(); i++) {

            cout << vec[i] << " ";

        }
        cout << "\n\n\n";

    }


    // Функция заполнения 1D вектора
    void Fill_1D_Vector(vector<int>& vec) {

        for (unsigned i = 0; i < vec.size(); i++) {

            vec[i] = rand() % 200 - 100;

        }

    }


}


// Пространство имён Expection. Оно создано для функций, методов без вектора
namespace Expection {


    float sum(float a, float b) { return a + b; }

    void fac(unsigned &f) {

        unsigned s = f; // Создаём переменную для ограничения цикла for, ибо f будет менятся...

        for (unsigned i = 2; i < s; i++) {

            f *= i;

        }
    }
}


// Пространство имён Expection. Оно создано для использования новой функции fac
namespace Lol {

    unsigned fac(unsigned f) {

        if ((f == 1) || (f == 0)) { return 1; }

        else { return f * fac(f - 1); }

    }
}






int main()
{
    setlocale(LC_ALL, "Russian");

    unsigned n = 10;


    // Создаём векторы для теста
    vector<int> vec1(n);
    vector<int> vec2;  
    vector<float> vec3(n);


    // Заполняем, выаоди векторы для тестов...
    VecFun::Fill_1D_Vector(vec1);

    using namespace VecFun;

    Show_1D_Vector(vec1);

    Fill_1D_Vector(vec2);
    Show_1D_Vector(vec2);

    // "Играемся" с функцией и методом получения факториала
    unsigned rn = rand() % n;
    unsigned fac = 5;

    // Выводим результаты функции и метода
    cout << "\n\n\t\tФакториал Lol: " << Lol::fac(fac);
    Expection::fac(fac);
    cout << "\n\n\t\tФакториал Expection: " << fac << "\n\n\n";

    
    system("pause");
    return 0;
}