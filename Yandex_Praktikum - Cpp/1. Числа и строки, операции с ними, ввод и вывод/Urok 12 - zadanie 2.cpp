#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 0;
    cin >> a;
    string test = " documents found"s;
    test = to_string(a) + test;
    cout << test;
    return 0;
}




/*
Напишите программу, которая считывает число (количество документов) и выводит на экран <число документов> documents found. Сначала сформируйте строку с ответом, только потом выведите её на экран целиком.
Формат ввода: 2
Формат вывода: 2 documents found
*/