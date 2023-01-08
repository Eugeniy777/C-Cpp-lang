#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string FindWidespreadBird(const vector<string> &types)
{
    map<string, int> bird_count;
    for (const string &type : types)
    {
        bird_count[type]++;
    }
    int current_max = 0;
    string widespread_bird;
    for (auto &[bird, count] : bird_count)
    {
        if (count > current_max)
        {
            current_max = count;
            widespread_bird = bird;
        }
    }
    return widespread_bird;
}

int main()
{
    vector<string> bird_types1 = {"zyablik"s, "sinica"s, "vorobey"s, "zyablik"s, "sinica"s, "sinica"s};
    if (FindWidespreadBird(bird_types1) == "sinica"s)
    {
        cout << "Correct"s << endl;
    }
    else
    {
        cout << "Not correct"s << endl;
    }

    vector<string> bird_types2 = {"ruh"s, "sirin"s, "blue bird of fortune"s, "finist"s, "fenix"s};
    if (FindWidespreadBird(bird_types2) == "blue bird of fortune"s)
    {
        cout << "Correct"s << endl;
    }
    else
    {
        cout << "Not correct"s << endl;
    }
}




/*
Задание
Представьте, что провели выходные за бёрдвотчингом. Вооружившись биноклем, блокнотом и фотоаппаратом с огромным объективом, вы два дня просидели в кустах у большого водоёма. Чтобы не спугнуть птиц, вы боялись пошевелиться, и записи получились не очень хорошо структурированными. Все статистические данные вы решили посчитать, когда фотографии будут готовы. Теперь они готовы, и каждая фотография подписана именем птицы, изображённой на ней. Каждая птица сфотографирована только единожды, но птицы могли быть одного вида. Используйте эти данные и определите самую распространённую птицу в этих краях.
Напишите функцию FindWidespreadBird, принимающую на вход вектор названий птиц и возвращающую самую популярную из них.
Как будет тестироваться ваш код

    Тренажёр будет проверять только работу функции FindWidespreadBird, вызывая её с разными входными векторами.
    Функция main из вашего кода игнорируется.
    Будет проверено, что функция ничего не считывает из cin и ничего не выводит в cout.

Требования

    При решении задачи используйте словарь: сохраните в него количество наблюдений каждого вида птиц, а затем выберите птицу с наибольшим значением.
    Если несколько птиц встретились одинаковое количество раз, функция должна возвратить первую по алфавиту.

Ограничения

    На вход функции подаётся непустой вектор.
    Названия птиц записаны строчными буквами.

Примеры

    Аргумент: {"zyablik"s, "sinitsa"s, "vorobey"s, "zyablik"s, "sinitsa"s, "sinitsa"s}.
    Значение функции: sinitsa.

    Аргумент: {"ruh"s, "sirin"s, "blue bird of fortune"s, "finist"s, "fenix"s}.
    Значение функции: blue bird of fortune.
*/