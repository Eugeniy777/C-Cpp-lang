#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CountStartsWithA(const vector<string>& xs) {
    // посчитайте число строк, начинающихс¤ на букву A или a
    vector<bool>s;
    for(auto c : xs){
        if(c[0] == 'A' || c[0] == 'a'){
            s.push_back(true);
        }
    }
    return s.size();
}

int main() {
    // не меняйте тело main
    cout << CountStartsWithA({"And"s, "another"s, "one"s, "gone"s, "another"s,
                              "one"s, "bites"s, "the"s, "dust"s});
    return 0;
}




/*
Задание 1

Напишите функцию, которая принимает вектор строк и возвращает число строк, начинающихся на большую или маленькую английскую букву "a".
*/




/*
Решение от авторов:


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
/* FOR SUPPORT: определяем функцию для проверки что слово начинается на 'A' или 'a'
 * принимает константную ссылку на строку str
 * возвращает bool - верно или нет */
bool StartsWithA(const string& str) {
    return !str.empty() && (str[0] == 'A' || str[0] == 'a');
}
 
/* FOR SUPPORT: определяем функцию для подсчёта количества слов начинающихся на 'A' или 'a'
 * принимает константную ссылку на вектор строк xs
 * возвращает число - количество строк */
int CountStartsWithA(const vector<string>& xs) {
    /* FOR SUPPORT: считаем количество слов с помощью алгоритма из стандартной библиотеки
     * count_if считает количество элементов в контейнере для которых функция 3-ий параметр (StartsWithA) возвращает истину */
    return count_if(xs.begin(), xs.end(), StartsWithA);
}
 
int main() {
    // не меняйте содержимое функции main
    /* FOR SUPPORT: вызываем функцию */
    cout << CountStartsWithA({"And"s, "another"s, "one"s, "gone"s, "another"s, "one"s, "bites"s, "the"s, "dust"s}) << endl;
}
*/