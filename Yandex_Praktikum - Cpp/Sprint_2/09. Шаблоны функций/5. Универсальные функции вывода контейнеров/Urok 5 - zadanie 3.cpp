#include <iostream>
#include <vector>
#include <set>
#include <locale.h>

using namespace std;

template <typename V>
ostream &operator<<(ostream &out, const vector<V> &container)
{
    bool first = true;
    for (const auto &element : container)
    {
        if (!first)
        {
            out << ", "s;
        }
        first = false;
        out << element;
    }
    return out;
}

template <typename S>
ostream &operator<<(ostream &out, const set<S> &container)
{
    bool first = true;
    for (const auto &element : container)
    {
        if (!first)
        {
            out << ", "s;
        }
        first = false;
        out << element;
    }
    return out;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    const vector<int> ages = {10, 5, 2, 12};
    cout << ages << endl;

    const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
    cout << cats << endl;
}




/*
Задание 1


Научите функцию вывода работать не только с векторами, но и со множествами.

Пример

const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
cout << cats << endl; 

Вывод

Белка, Георгий, Мурка, Рюрик 
*/




/*
// Решение от авторов:


#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
template <typename Element>
ostream& operator<<(ostream& out, const vector<Element>& container) {
    bool is_first = true;
    for (const auto& element : container) {
        if (!is_first) {
            out << ", "s;
        }
        is_first = false;
        out << element;
    }
    return out;
}
 
template <typename Element>
ostream& operator<<(ostream& out, const set<Element>& container) {
    bool is_first = true;
    for (const auto& element : container) {
        if (!is_first) {
            out << ", "s;
        }
        is_first = false;
        out << element;
    }
    return out;
}
 
int main() {
    const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
    cout << cats << endl;
}
*/