#include <iostream>
#include <vector>
#include <set>
#include <map>

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

// vectop
template <typename V>
ostream &operator<<(ostream &out, const vector<V> &container)
{
    out << "[";
    Print(out, container);
    out << "]";
    return out;
}

// set
template <typename S>
ostream &operator<<(ostream &out, const set<S> &container)
{
    out << "{";
    Print(out, container);
    out << "}";
    return out;
}

// pair
template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
    return out << '(' << p.first << ", "s << p.second << ')';
}

// map
template <typename Key, typename Value>
ostream &operator<<(ostream &out, const map<Key, Value> &container)
{
    out << "<";
    Print(out, container);
    out << ">";
    return out;
}

int main()
{
    const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
    cout << cats << endl;

    const vector<int> ages = {10, 5, 2, 12};
    cout << ages << endl;

    const map<string, int> cat_ages = {
    {"Мурка"s, 10}, 
    {"Белка"s, 5},
    {"Георгий"s, 2}, 
    {"Рюрик"s, 12}
};
cout << cat_ages << endl;
}




/*
Задание 1


Научитесь выводить словари. Содержимое словаря должно быть заключено в угловые скобки, а каждая пара ключ-значение — в круглые.
Пусть функция Print выводит словарь без угловых скобок. Ни для каких других типов, кроме векторов, множеств и словарей, вызывать Print не нужно.
Пример

const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
cout << cats << endl;
const vector<int> ages = {10, 5, 2, 12};
cout << ages << endl;
const map<string, int> cat_ages = {
    {"Мурка"s, 10}, 
    {"Белка"s, 5},
    {"Георгий"s, 2}, 
    {"Рюрик"s, 12}
};
cout << cat_ages << endl; 

Вывод

{Белка, Георгий, Мурка, Рюрик}
[10, 5, 2, 12]
<(Белка, 5), (Георгий, 2), (Мурка, 10), (Рюрик, 12)> 
*/




/*
// Решение от авторов:


#include <iostream>
#include <map>
#include <set>
#include <vector>
 
using namespace std;
 
template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
    return out << '(' << p.first << ", "s << p.second << ')';
}
 
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
 
template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& container) {
    out << '<';
    Print(out, container);
    out << '>';
    return out;
}
 
int main() {
    const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
    cout << cats << endl;
 
    const vector<int> ages = {10, 5, 2, 12};
    cout << ages << endl;
 
    const map<string, int> cat_ages = {
        {"Мурка"s, 10},
        {"Белка"s, 5},
        {"Георгий"s, 2},
        {"Рюрик"s, 12}
    };
    cout << cat_ages << endl;
}
*/