#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

int main()
{
    map<string, Date> birth_dates;
    string name;

    // читаем число записей из потока ввода
    int count;
    cin >> count;

    // читаем все записи, применив цикл; циклы изучаются в теме 2
    for (int i = 0; i < count; ++i)
    {
        int year, month, day;
        cin >> name >> year >> month >> day;
        birth_dates[name] = {year, month, day};
    }

    vector<string> born_in_may;

    // применяем цикл по константности; константность изучается в теме 6
    for (const auto &[name, date] : birth_dates)
    {
        if (date.month == 5)
        {
            born_in_may.push_back(name); // добавляем имя в конец
        }
    }

    // сортируем массив по алфавиту; сортировка изучается в платной части
    sort(born_in_may.begin(), born_in_may.end());

    for (const auto &name : born_in_may)
    {
        cout << name << ' ';
    }
    cout << endl;
}