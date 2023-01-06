#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ComputeAbs(int);
float ComputeAbs(float);
double ComputeAbs(double);
vector<int> ComputeAbs(vector<int>);

int main()
{
    // Тестируем версию int
    cout << "|100| = "s << ComputeAbs(100) << endl;
    cout << "|0| = "s << ComputeAbs(0) << endl;
    cout << "|-50| = "s << ComputeAbs(-50) << endl;

    // Тестируем версию float. Можно задать значение float
    // добавив после цифр букву f
    cout << "|3.141592f| = "s << ComputeAbs(3.141592f) << endl;
    cout << "|0.f| = "s << ComputeAbs(0.f) << endl;
    cout << "|-3.141592f| = "s << ComputeAbs(-3.141592f) << endl;

    // Тестируем версию double
    cout << "|3.141592| = "s << ComputeAbs(3.141592) << endl;
    cout << "|0| = "s << ComputeAbs(0) << endl;
    cout << "|-3.141592| = "s << ComputeAbs(-3.141592) << endl;

    // Тестируем версию vector
    int idx = 0;
    vector input_data = {10, 20, -30, -50, 100};
    for (int x : ComputeAbs(input_data))
    {
    // Операция ++ увеличивает значение целочисленной переменной на 1.
    // Результатом операции ++ становится значение до увеличения.
    cout << "|"s << input_data[idx++] << "| = "s << x << endl;
    }
}

// четыре функции ComputeAbs
int ComputeAbs(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}

float ComputeAbs(float x)
{
    if (x < 0)
        return -x;
    else
        return x;
}

double ComputeAbs(double x)
{
    if (x < 0)
        return -x;
    else
        return x;
}

vector<int> ComputeAbs(vector<int> x)
{
    vector<int> newx;
    for (auto m : x)
    {
        if (m < 0)
            newx.push_back(-m);
        else
            newx.push_back(m);
    }
    return newx;
}



/*
Напишите функции для вычисления модуля числа. Разработайте четыре функции, которые будут оперировать со следующими типами данных:

    int,
    float,
    double,
    vector<int>.

Первые три вычисляют модуль и возвращают значения того же типа. Четвёртая вычисляет модуль каждого значения в векторе, формирует новый вектор, состоящий из вычисленных модулей и возвращает его.
Все функции назовите ComputeAbs. Различаться они будут типами единственного параметра и возвращаемого значения.
Требования

    Реализуйте функции в файле functions.cpp.
    Не меняйте содержимое main.cpp.
    Возвращаемый тип всех функций совпадает с типом их единственного параметра.

Пример

    Вызов ComputeAbs(-5) возвращает значение 5 типа int.
    Вызов ComputeAbs(3.1415) возвращает 3.1415 типа double.
    Если float x = -10.5, вызов ComputeAbs(x) возвращает 10.5 типа float.
    Вызов ComputeAbs({1, 2, -3, 40, -50}) возвращает вектор типа vector<int> со значениями 1, 2, 3, 40, 50.
*/