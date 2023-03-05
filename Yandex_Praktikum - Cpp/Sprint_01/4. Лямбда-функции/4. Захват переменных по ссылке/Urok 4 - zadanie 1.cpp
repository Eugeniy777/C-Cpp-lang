#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
 
using namespace std;

int CountAndAddNewDogs(const vector<string>& new_dogs, const map<string, int>& max_amount, map<string, int>& shelter) {
    return count_if(new_dogs.begin(), new_dogs.end(), [&max_amount, &shelter](const string& dog) {
            int& current_amount = shelter[dog];
            if (max_amount.at(dog) > current_amount) {
                ++current_amount;
                return true;
            } else {
                return false;
            }
        });
}
 
int main() {
    map<string, int> shelter = {{"landseer"s, 1}, {"otterhound"s, 2}, {"pekingese"s, 2}, {"pointer"s, 3}};
    map<string, int> max_amount = {{"landseer"s, 2}, {"otterhound"s, 3}, {"pekingese"s, 4}, {"pointer"s, 7}};
    cout << CountAndAddNewDogs({"landseer"s, "otterhound"s, "otterhound"s, "otterhound"s, "pointer"s}, max_amount, shelter) << endl;
}




/*
Задание 1


В приют привозят собак разных пород. В словаре shelter по названию хранится количество особей каждого вида на текущий момент. Приют может содержать определённое количество собак каждой породы. Оно указано в словаре max_amount. 
Напишите функцию, которая будет на основании вектора с именами поступивших собак обновлять словарь shelter и возвращать количество  новоприбывших собак, которых смог принять приют. Гарантируется, что никакие другие собаки, кроме известных из словаря max_amount, в приют не приедут.
Пример входных данных для функции

map<string, int>& shelter = {{"landseer"s, 1}, {"otterhound"s, 2}, {"pekingese"s, 2}, {"pointer"s, 3}};
const map<string, int>& max_amount = {{"landseer"s, 2}, {"otterhound"s, 3}, {"pekingese"s, 4}, {"pointer"s, 7}};
const vector<string>& new_dogs = {"landseer"s, "otterhound"s, "otterhound"s, "otterhound"s, "pointer"s}; 

Пример вывода программы

3 

Как будет тестироваться ваш код
Тренажёр проверит работу функции CountAndAddNewDogs, передавая ей различные комбинации входных данных и сравнивая возвращаемое значение и содержимое контейнера shelter c ожидаемым.
*/




/*
// Решение от авторов:


#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
 
using namespace std;
 
/* определяем функцию для подсчета количества принятых собак в приют
 * принимает константную ссылку на вектор строк с новыми собаками new_dogs
 * * * * * * константную ссылку на словарь максимальной вместимости приюта
 * * * * * * константную ссылку на словарь приюта
 * возвращает число - количества принятых собак в приют */
int CountAndAddNewDogs(const vector<string>& new_dogs,
                       const map<string, int>& max_amount,
                       map<string, int>& shelter) {
    /* возвращаем количество принятых собак в приют
     * передаем std::count_if 3-им параметром лямбда-функцию с захваченными по ссылке переменным,
     * * которая проверяет что собаку определенного типа еще можно разместить в приюте */
    return count_if(new_dogs.begin(), new_dogs.end(),
        [&max_amount, &shelter](const string& name) {
            /* объявляем и инициализируем ссылку на количество собак в приюте породы name
             * использование ссылки позволяет не искать один ключ в словаре дважды */
            int& current_amount = shelter[name];
            /* условие на выполнение блока:
             * * текущее количество собак породы name меньше максимальной вместимости породы name */
            if (current_amount < max_amount.at(name)) {
                /* "заселяем собаку" - увеличиваем количество собак породы name */
                ++current_amount;
                /* возвращаем истину, тем самым учитываем эту собаку как добавленную */
                return true;
            } else {
                /* возвращаем ложь, тем самым не учитываем эту собаку как добавленную */
                return false;
            }
        });
}
 
int main() {
    /* объявляем и инициализируем словарь из пар строк и чисел парами, для хранения приюта */
    map<string, int> shelter {
        /* 1-я пара */
        {"shepard"s, 1},
        /* 2-я пара */
        {"corgie"s, 3},
    };
 
    /* объявляем и инициализируем словарь из пар строк и чисел парами, для хранения максимальной вместимости приюта */
    map<string, int> max_amount {
        /* FOR SUPPORT: 1-я пара */
        {"shepard"s, 2},
        /* FOR SUPPORT: 2-я пара */
        {"corgie"s, 3},
        /* FOR SUPPORT: 3-я пара */
        {"shiba inu"s, 1},
    };
 
    /* выводим то, что вернет функция CountAndAddNewDogs */
    cout << CountAndAddNewDogs({"shepard"s, "shiba inu"s, "shiba inu"s, "corgie"s}, max_amount, shelter) << endl;
}
*/