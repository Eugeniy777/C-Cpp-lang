#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 0, b = 0, S = 0;
    cin >> a >> b;
    S = a * b;
    int sizze = to_string(S).size();
    // Выведите произведение их суммы на количество чисел в записи суммы
    cout << S * sizze << endl;

    /*-----------------
    -------------------
    -------------------
    -------------------
    -----------------*/

    /* 
    Задание 2
    Напишите программу, которая считывает число (количество документов) и выводит 
    на экран <число документов> documents found. Сначала сформируйте строку с 
    ответом, только потом выведите её на экран целиком.
    Формат ввода: 2
    Формат вывода: 2 documents found
    */
    int a = 0;
    cin >> a;
    string test = " documents found"s;
    test = to_string(a) + test;
    cout << test;
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}