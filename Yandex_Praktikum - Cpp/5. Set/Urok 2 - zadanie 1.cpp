#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

int size_of_set;
    cout << "Enter size of set: " << endl;
    cin >> size_of_set;
    set<string> new_set;
    for (int i = 0; i < size_of_set; ++i)
    {
        string word;
        cout << "Enter word: " << endl;
        cin >> word;
        new_set.insert(word);
    }
    cout << new_set.size() << endl;
    return 0;
}



/*
Первое решение - не принято тренажером.

    string stroka;
    cout << "Enter string: " << endl;
    getline(cin, stroka);
    set<string> new_set;
    string word;
    for (int i = 0; i <= stroka.size(); ++i)
    {
        if ((stroka[i] != ' ') && (stroka[i] != '\0'))
        {
            word += stroka[i];
        }
        else if (((stroka[i] == ' ') || (stroka[i] == '\0')) && (stroka[i - 1] != ' '))
        {
            if (word == ""s)
            {
                continue;
            }
            new_set.insert(word);
            word = ""s;
        }
    }
    cout << new_set.size() << endl;
*/


    




/*
Задание:
Множества позволяют оставлять в наборе элементов только уникальные. Найдите, сколько уникальных строк ввёл пользователь.

Формат ввода:
Сначала вводится количество строк N, затем сами строки, разделённые пробелом. Строки могут состоять только из латинских букв, цифр и символов подчёркивания.

Формат вывода:
Выведите единственное целое число — количество уникальных строк в данном наборе.

Примеры:
Ввод:				Вывод:
6 cat dog cat fish dog dog	3
1 apple				1
3 c plus plus			2
*/




/*
Авторское решение:
#include <iostream>
#include <string>
#include <set>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    set<string> strings;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strings.insert(s);
    }
    cout << strings.size() << endl;
 
    return 0;
}

*/