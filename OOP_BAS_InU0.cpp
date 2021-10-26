#include <iostream>
#include <vector> // Подключённые библиотеки, нужные для работы...
#include <fstream>


using namespace std; // Для моего удобства



// Вывод 2Д массива на экран 
void Show_2D_Int_Vector(const vector<vector<int>> &v) {

    cout << "\n\n";

    for (unsigned i = 0; i < v.size(); i++) {
        cout << "\t";
        for (unsigned j = 0; j < v[i].size(); j++) {

            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n\n";

}

// Заполнение 2Д массива случайными int переменными
void Random_Fill_2D_Int_Vector(vector<vector<int>>& v) {

    for (unsigned i = 0; i < v.size(); i++) {

        v[i].resize(v.size());

        for (unsigned j = 0; j < v[i].size(); j++) {

            v[i][j] = rand() % 200 - 80;

        }
    }

}








// Запись 2Д массива в файл
void Record_2D_Int_Vector_to_File(fstream& f, const vector<vector<int>>& v) {

    f << "\n\n";

    for (unsigned i = 0; i < v.size(); i++) {
        f << "\t";
        for (unsigned j = 0; j < v[i].size(); j++) {

            f << v[i][j] << "\t";
        }
        f << endl;
    }
    f << "\n\n";

}

// Todo:
// Чтение файла
void File_Read(fstream& f, string file_name) {

    string s;

    f.open(file_name);

    if (f.is_open()) {

        f >> s;
        std::cout << s;

    }

    f.close();


}


// Проверка на наличие файла
bool File_Check(fstream &f) {

    if (!f) {
        throw (invalid_argument("Нет там такого файла..."));
    }
    else {
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Задаём размерность массива
    unsigned n = 5;

    // Создаём 2Д массив
    vector<vector<int>> Vector0(n);


    // Заполняем данный массив
    cout << "\n\nСлучайный 2-ухмерный массив:";
    Random_Fill_2D_Int_Vector(Vector0);
    Show_2D_Int_Vector(Vector0);


    cout << "Работа с файлом:\n";
    // Создаём fstream для дальнейшей работы с файлом
    fstream F_Arr0("R:\Array0.txt");
    fstream F1("R:\Array1.txt");
    

    // Проверка наличия файла
    /*
    * cout << "\nПроверка наличия файла:\n";
    try {
        File_Check(F_Arr0);
        cout << "\nФайл по указанному пути есть!\n";
    }
    catch (invalid_argument e) {

        cout << "\nФайла, по указанному пути не существует!\n";

    }
    */
    




    // Проверяем чтение\запись файла...
    File_Read(F_Arr0, "Array0.txt");



    cout << "\n\n\n";
    system("pause"); // Делаем доп. паузу для удобства пользователя
    return 0;
}