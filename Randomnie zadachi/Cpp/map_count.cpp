#include <iostream>
#include <map>
#include <string>

using namespace std;
int main()
{
    map<string, int> days_here = {
        {"Karl"s, 10}, {"Gustav"s, 3}, {"Richard"s, 42}, {"Wolfgang"s, 15}};

    // Заключим объявление и использование переменной в фигурные скобки,
    // чтобы показать, что она нужна лишь на несколько строк:
    {
        map<string, int> days_here_new;

        // присваиваем уже в новый словарь
        for (const auto &[name, days] : days_here)
        {
            days_here_new["Mr. "s + name] = days;
        }

        days_here = days_here_new;
    }
    
    // Теперь ключи обрели префикс:
    cout << "Mr. Karl has been here for "s << days_here["Mr. Karl"s] << " days"s << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"s << endl;
    for (auto &[name, days] : days_here)
    {
        cout << name << " has been here for "s << days_here[name] << " days"s << endl;
    }
    return 0;
}