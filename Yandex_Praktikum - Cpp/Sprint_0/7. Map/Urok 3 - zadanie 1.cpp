#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CheckAnagram(const string& s1, const string& s2) {
    map<char, int> map_1;
    for(auto& s : s1){
        ++map_1[s];
    }
    map<char, int> map_2;
    for(auto& s : s2){
        ++map_2[s];
    }
    if(map_1 == map_2){
        return true;
    }
    return false;
}

// напишем небольшую функцию для проверки
void CheckIsTrue(bool value) {
    if (value) {
        cout << "Test passed :)"s << endl;
    } else {
        cout << "Test failed :("s << endl;
    }
}

int main() {
    CheckIsTrue(CheckAnagram("tea"s, "eat"s));
    CheckIsTrue(!CheckAnagram("battle"s, "beatle"s));
    CheckIsTrue(!CheckAnagram("lift"s, "elevator"s));
    CheckIsTrue(CheckAnagram("ocean"s, "canoe"s));
}




/*
Задание
Слова называются анаграммами, если одно из них можно получить перестановкой букв в другом. Например, “eat” и “tea” — анаграммы, потому что состоят из одних и тех же букв в разном порядке.
Слова “battle” и “beatle” — не анаграммы. В первом две буквы “t”, а во втором две “e”.
Напишите функцию CheckAnagram, которая принимает два слова и возвращает true, если они анаграммы.
Как будет тестироваться ваша программа

    Тесты проверят правильную работу функции CheckAnagram.
    В качестве параметров будут передаваться слова, целиком состоящие из строчных английских букв.
    Функция main, которую вы напишете, учитываться не будет.

Ограничения

    Ничего не выводите в cout и не читайте из cin.
    Не меняйте название функции — CheckAnagram.

Примеры

    Слова hare и rhea. Результат true.
    Слова battle и beatle. Результат false.
    Слова eat и tea. Результат true.
    Слова lift и elevator. Результат false.
*/




/*
//authors result

#include <iostream>
#include <string>
#include <map>
 
using namespace std;
 
map<char, int> BuildCharCounters(const string& word) {
    map<char, int> counters;
    for (char c : word) {
        ++counters[c];
    }
    return counters;
}
 
bool CheckAnagram(const string& s1, const string& s2) {
    return BuildCharCounters(s1) == BuildCharCounters(s2);
}
 
// напишем небольшую функцию для проверки
void CheckIsTrue(bool value) {
    if (value) {
        cout << "Test passed :)"s << endl;
    } else {
        cout << "Test failed :("s << endl;
    }
}
 
int main() {
    CheckIsTrue(CheckAnagram("tea"s, "eat"s));
    CheckIsTrue(!CheckAnagram("battle"s, "beatle"s));
    CheckIsTrue(!CheckAnagram("lift"s, "elevator"s));
    CheckIsTrue(CheckAnagram("ocean"s, "canoe"s));
}
*/




/*
#include <iostream>
#include <string>

using namespace std;

bool CheckAnagram(const string &s1, const string &s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 != len2)
        return false;
    else
    {
        char c;
        int count1, count2;
        for (int x = 0; x < len1; x++)
        {
            c = s1[x];
            count1 = 0;
            count2 = 0;
            for (int z = 0; z < len1; z++)
                if (s1[z] == c)
                    count1++;
            for (int y = 0; y < len2; y++)
                if (s2[y] == c)
                    count2++;
            if (count1 != count2)
                return false;
        }
    }
    return true;
}
// напишем небольшую функцию для проверки
void CheckIsTrue(bool value)
{
    if (value)
    {
        cout << "Test passed :)"s << endl;
    }
    else
    {
        cout << "Test failed :("s << endl;
    }
}
int main()
{
    CheckIsTrue(CheckAnagram("tea"s, "eat"s));
    CheckIsTrue(!CheckAnagram("battle"s, "beatle"s));
    CheckIsTrue(!CheckAnagram("lift"s, "elevator"s));
    CheckIsTrue(CheckAnagram("ocean"s, "canoe"s));
}
*/