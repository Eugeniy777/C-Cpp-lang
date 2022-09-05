#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin >> q;
    string s = ""s;

    vector<bool> ochered;

    for (int i = 0; i < q; ++i)
    {
        string oper;
        cin >> oper;
        if (oper == "WORRY"s)
        {
            int index;
            cin >> index;
            ochered[index] = true;
        }
        else if (oper == "HAPPY"s)
        {
            int index;
            cin >> index;
            ochered[index] = false;
        }
        else if (oper == "COME"s)
        {
            int count;
            cin >> count;
            ochered.resize(ochered.size() + count, false);
        }
        else if (oper == "LAST_WORRY"s)
        {
            if (ochered.back() == false)
            {
                cout << "happy"s << endl;
            }
            else if (ochered.back() == true)
            {
                cout << "worry"s << endl;
            }
        }
        else if (oper == "WORRY_COUNT"s)
        {
            auto worry_count = count(ochered.begin(), ochered.end(), true);
            cout << worry_count << endl;
        }
    }
    return 0;
}




/*
Задание 2
В программе симуляции очереди реализуйте новую команду WORRY_COUNT. Она должна вывести количество беспокойных клиентов в очереди.
Для этого циклом пройдитесь по вектору. При появлении значения true в теле цикла прибавляйте единицу к заранее созданной переменной.

Формат ввода:
На вход программе подаётся количество операций Q, затем в следующих Q строках — сами операции.
Программа должна поддерживать все те же операции, что и предыдущая:

    WORRY i — пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося.
    HAPPY i — пометить i-го человека (в нумерации с 0) как успокоившегося.
    COME k — добавить k спокойных человек в конец очереди. Если k отрицательно, то нужно убрать k человек из конца очереди.
    LAST_WORRY — напечатать worry, если последний в очереди беспокоится, либо happy, если он спокоен.

Также добавляется новая команда:

    WORRY_COUNT — посчитать количество беспокойных в очереди и вывести его в cout.

Формат вывода:
Для каждой операции LAST_WORRY выведите одно слово: worry или happy.
Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокойных в очереди на данный момент.
Каждую выводимую строку заканчивайте манипулятором endl.

Ограничения:
Тренажёр подаст на вход программы только допустимые значения, поэтому проверять корректность входных данных не нужно.

Пример ввода:

8
COME 5
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 5
WORRY_COUNT 

Пример вывода:

1
2 

*/




/*
Авторское решение:

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
      int q;
      cin >> q;

    vector<bool> queue;
    
      for (int i = 0; i < q; ++i) {
            string operation_code;
            cin >> operation_code;
        
            if (operation_code == "WORRY"s) {
                int index;
            cin >> index;

            queue[index] = true;
            } else if (operation_code == "HAPPY"s) {
                int index;
            cin >> index;

            queue[index] = false;
            } else if (operation_code == "COME"s) {
                int count;
            cin >> count;

            queue.resize(queue.size() + count, false);
            } else if (operation_code == "LAST_WORRY"s)  {
                    if (queue.back()) {
                cout << "worry"s << endl;
            } else {
                cout << "happy"s << endl;
            }
            } else if (operation_code == "WORRY_COUNT"s)  {
                    int count = 0;
            for (bool elem : queue) {
                if (elem) {
                    ++count;
                }
            }
            cout << count << endl;
            }
      }
}

*/