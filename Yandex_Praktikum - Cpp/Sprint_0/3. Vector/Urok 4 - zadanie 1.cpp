#include <iostream>
#include <string>
#include <vector>

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
    }
    return 0;
}




/*
Задание 1
Все стояли в очередях. Порой кажется, что очередь вовсе не двигается — тогда от отчаяния хочется уйти. Но из середины очереди уходить обидно — можно потерять ценное место. То и дело кто-нибудь в очереди начинает беспокоиться и раздражать окружающих одними и теми же вопросами. А потом отвлекается на что-то и успокаивается.
Симулировать подобную очередь в компьютере можно с использованием вектора булевых значений: false будет соответствовать спокойно ждущему посетителю, а true — беспокойному.
Недостаток вектора для этой задачи в том, что если очередь всё же продвинется, то нужно будет удалить элемент из начала, а это долгая операция. Поэтому в нашей задаче очередь двигаться не будет, но в её конец люди будут то приходить, то уходить из него.
Напишите программу для симуляции такой очереди. Она должна обрабатывать несколько видов запросов, описанных в формате ввода.
Изначально очередь пуста.

Формат ввода:
На вход программе подаётся количество операций Q, затем их описания.
Операция кодируется названием и числовым аргументом. Программа должна обрабатывать следующие операции:

    WORRY i — пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося.
    HAPPY i — пометить i-го человека (в нумерации с 0) как успокоившегося.
    COME k — добавить k спокойных человек в конец очереди. Если k отрицательно, то нужно убрать −k человек из конца очереди.
    LAST_WORRY — напечатать worry, если последний в очереди беспокоится, либо happy, если он спокоен.

Формат вывода:
Для каждой операции LAST_WORRY выведите одно слово: worry или happy.
Каждый вывод заканчивайте манипулятором endl.

Ограничения:

    Для каждой операции WORRY i и HAPPY i гарантируется, что человек с номером i существует в очереди на момент операции.
    При операции LAST_WORRY гарантируется, что очередь не пуста.
    Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

Указанные гарантии справедливы для всех запросов. Проверять их не нужно, пишите программу, считая, что входные данные корректны.

Пример ввода:

8
COME 5
WORRY 1
WORRY 4
COME -2
LAST_WORRY
COME 3
WORRY 5
LAST_WORRY 

Пример вывода

happy
worry 

*/




/*
Правильное решение:

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
        }
    }
}

*/