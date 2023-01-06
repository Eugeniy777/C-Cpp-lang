#include <iostream>
#include <string>
#include <vector>

using namespace std;

int FindInVector(vector<string> haystack, string needle);
void PrintVector(vector<string> v);
void TestFind(vector<string> haystack, string needle);

int main()
{
    TestFind({"zero"s, "one"s, "two"s, "three"s, "four"s, "five"s}, "four"s);
    TestFind({"one"s, "two"s, "three"s}, "four"s);
    TestFind({"to"s, "be"s, "or"s, "not"s, "to"s, "be"s}, "be"s);
}



int FindInVector(vector<string> haystack, string needle)
{
    int index = 0;
    for (string s : haystack)
    {
        if (s == needle)
        {
            return index;
        }
        index += 1;
    }
    return -1;
}

// Не меняйте следующие функции
void PrintVector(vector<string> v)
{
    bool is_first = true;
    for (string s : v)
    {
        if (!is_first)
        {
            cout << ", "s;
        }
        cout << s;
        is_first = false;
    }
}

void TestFind(vector<string> haystack, string needle)
{
    int result = FindInVector(haystack, needle);

    if (result < 0)
    {
        cout << needle << " not found in "s;
        PrintVector(haystack);
        cout << endl;
    }
    else if (result < haystack.size() && haystack[result] == needle)
    {
        cout << needle << " found at "s << result << endl;
    }
    else
    {
        cout << "Incorrect result"s << endl;
    }
}



/*
Задание 2
Определите функцию FindInVector, которая ищет заданную строку в векторе. Если строка найдена, возвратите её индекс в векторе. Если не найдена — возвратите -1.
Аргументы функции поиска по традиции называются стогом сена и иголкой. По-английски это haystack и needle. Как называть аргументы любой функции — ваше дело, главное, чтобы они были правильных типов и шли в правильном порядке. Предлагаются такие названия:

    haystack типа vector<string> — вектор, где нужно осуществить поиск,
    needle типа string — строка, которую нужно найти.

Возвращаемый тип — int.
Требования

    Функция должна называться FindInVector и принимать два аргумента типов vector<string> и string.
    Если искомая строка встречается несколько раз, нужно вернуть индекс первого вхождения.
    Когда строка найдена, нужно прервать поиск командой return и сразу возвратить ответ.
    Свою функцию расположите в начале файла functions.cpp

Пример

    Вызов FindInVector({"zero"s, "one"s, "two"s, "three"s, "four"s, "five"s}, "four"s) возвращает 4.
    Вызов FindInVector({"one"s, "two"s, "three"s}, "four"s) возвращает -1.
    Вызов FindInVector({"to"s, "be"s, "or"s, "not"s, "to"s, "be"s}, "be"s) возвращает 1.
*/