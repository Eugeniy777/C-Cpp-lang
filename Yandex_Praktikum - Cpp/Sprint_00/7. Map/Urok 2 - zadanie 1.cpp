#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> BuildReversedMap(const map<string, string> &input_map)
{
    map<string, string> new_map;
    for (const auto &[key, value] : input_map)
    {
        new_map.insert({value, key});
    }
    return new_map;
}

int main()
{
    map<string, string> test1_input = {{"cat"s, "felis catus"s}, {"dog"s, "canis lupus"s}};
    map<string, string> test1_output = {{"felis catus"s, "cat"s}, {"canis lupus"s, "dog"s}};

    // Проверяем корректность BuildReversedMap на примере
    if (BuildReversedMap(test1_input) != test1_output)
    {
        cout << "BuildReversedMap returned wrong dictionary"s << endl;
    }
    else
    {
        cout << "everything is fine"s << endl;
    }
    return 0;
}




/*
Задание:
Иногда нужно срочно найти что-нибудь в значениях, а быстрый поиск работает только среди ключей. Напишите функцию BuildReversedMap, которая переворачивает словарь: ключи становятся значениями, а значения — ключами.
Функция должна работать со словарями типа map<string, string>.

Как будет тестироваться ваш код:
Будет проверяться только работа функции BuildeReversedMap. При этом функция main заменится на другую.
Ограничения:

    Не меняйте название и сигнатуру функции BuildReversedMap, данной в заготовке кода.
    Функция должна работать только со словарями вида map<string, string>.
    BuildReversedMap не должна выводить в cout, иначе программа не пройдёт проверки.
    Гарантируется, что все значения в передаваемых на вход словарях уникальны. Только в этом случае получится поменять ключи и значения местами, не потеряв ни одного элемента.

Примеры
Ключи и значения входного словаря:

    cat: felis catus,
    dog: canis lupus.

Ключи и значения возвращаемого значения:

    canis lupus: dog.
    felis catus: cat,

Ключи и значения входного словаря:

    cat: meow,
    cow: moo,
    dog: bark,
    owl: hoot.
    tiger: roar,

Ключи и значения возвращаемого значения:

    bark: dog,
    hoot: owl.
    meow: cat,
    moo: cow,
    roar: tiger,
*/




/*

Авторское решение:

#include <iostream>
#include <map>
#include <string>

using namespace std;


/* объявляем функцию для разворачивания словаря
 * принимает ссылку на константный словарь m
 * возвращает словарь */
map<string, string> BuildReversedMap(const map<string, string>& m) {
    /* объявляем словарь для хранения развернутого словаря */
    map<string, string> result;
    /* проходим по всем парам [ключ, значение] словаря */
    for (const auto& [key, value]: m) {
        /* записываем по ключу value значение key, т.е. разворачиваем пару */
        result[value] = key;
    }
    /* возвращаем словарь */
    return result;
}

int main() {
    map<string, string> test1_input = {{"cat"s, "felis catus"s}, 
                                       {"dog"s, "canis lupus"s}};
    map<string, string> test1_output = {{"felis catus"s, "cat"s}, 
                                        {"canis lupus"s, "dog"s}};

    // Проверяем корректность BuildReversedMap на примере 
    if (BuildReversedMap(test1_input) != test1_output) {
        cout << "BuildReversedMap returned wrong dictionary"s << endl;
    }

    // Добавьте ещё тесты, чтобы убедиться, что ваша функция работает верно
}