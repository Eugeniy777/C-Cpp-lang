#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int n = 0, max = 0, max_i = 0;
    getline(cin, s);
    for(int i = 0; i <= s.size(); i++)
    {
        if(s[i] == ' ' || s[i] == '\0')
        {
            if(n > max)
            {
                max = n;
                max_i = i - max;
            }
            n = 0;
        }
        else n++;
    }
    cout << s.substr(max_i, max);
    return 0;
}




/*
 Найдите в данной строке самое длинное слово и выведите его.

Входные данные:
Вводится одна строка. Слова в ней отделены одним пробелом.

Выходные данные:
Выведите самое длинное слово. Если таких слов несколько, то выводить нужно, которое встречается раньше.
*/