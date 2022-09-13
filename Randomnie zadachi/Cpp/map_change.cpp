#include <iostream>
#include <map>
#include <string>

using namespace std;
/*
map<string, string> BuildReversedMap(const map<string, string> &input_map)
{
    map<string, string> new_map;
    for (const auto &[key, value] : input_map)
    {
        new_map.insert({value, key});
    }
    return new_map;
}
*/
map<string, string> BuildReversedMap(const map<string, string>& input_map) {
    /* объявляем словарь для хранения развернутого словаря */
    map<string, string> new_map;
    /* проходим по всем парам [ключ, значение] словаря */
    for (const auto& [key, value]: input_map) {
        /* записываем по ключу value значение key, т.е. разворачиваем пару */
        new_map[value] = key;
    }
    /* возвращаем словарь */
    return new_map;
}

int main()
{
    map<string, string> test1_input = {{"cat"s, "felis catus"s}, {"dog"s, "canis lupus"s}};
    map<string, string> test1_output = {{"felis catus"s, "cat"s}, {"canis lupus"s, "dog"s}};

    if (BuildReversedMap(test1_input) != test1_output)
    {
        for (const auto &[key, value] : test1_input)
        {
            cout << key << " - "s << value << endl;
        }
        cout << "==========================="s << endl;
        for (const auto &[key, value] : test1_output)
        {
            cout << key << " - "s << value << endl;
        }
    }
    else
    {
        for (const auto &[key, value] : test1_input)
        {
            cout << key << " - "s << value << endl;
        }
        cout << "==========================="s << endl;
        for (const auto &[key, value] : test1_output)
        {
            cout << key << " - "s << value << endl;
        }
    }
    // Проверяем корректность BuildReversedMap на примере
    /*
    if (BuildReversedMap(test1_input) != test1_output)
    {
        cout << "BuildReversedMap returned wrong dictionary"s << endl;
    }
    else
    {
        cout << "everything is fine"s << endl;
    }
    */
    return 0;
}