#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename Container>
void Print(ostream &out, const Container &container)
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
}

template <typename V>
ostream &operator<<(ostream &out, const vector<V> &container)
{
    out << "[";
    Print(out, container);
    out << "]";
    return out;
}

template <typename S>
ostream &operator<<(ostream &out, const set<S> &container)
{
    out << "{";
    Print(out, container);
    out << "}";
    return out;
}

int main()
{
    const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
    cout << cats << endl;

    const vector<int> ages = {10, 5, 2, 12};
    cout << ages << endl;
}




/*
Задание 1


Сделайте вывод более нарядным: выводите содержимое вектора в квадратных скобках, а множества — в фигурных. Функция Print должна остаться прежней и не обрамлять вывод в скобки.
Пример

const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
cout << cats << endl;
const vector<int> ages = {10, 5, 2, 12};
cout << ages << endl; 

Вывод

{Белка, Георгий, Мурка, Рюрик}
[10, 5, 2, 12] 
*/




/*
// Решение от авторов:


#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
template <typename Container>
void Print(ostream& out, const Container& container) {
    bool is_first = true;
    for (const auto& element : container) {
        if (!is_first) {
            out << ", "s;
        }
        is_first = false;
        out << element;
    }
}
 
template <typename Element>
ostream& operator<<(ostream& out, const vector<Element>& container) {
    out << '[';
    Print(out, container);
    out << ']';
    return out;
}
 
template <typename Element>
ostream& operator<<(ostream& out, const set<Element>& container) {
    out << '{';
    Print(out, container);
    out << '}';
    return out;
}
 
int main() {
    const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
    cout << cats << endl;
 
    const vector<int> ages = {10, 5, 2, 12};
    cout << ages << endl;
}
*/