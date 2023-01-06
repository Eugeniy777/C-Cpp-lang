#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> SplitIntoWords(string text);

int main()
{
    string stroka;
    getline(cin, stroka);
    SplitIntoWords(stroka);
    return 0;
}

vector<string> SplitIntoWords(string text)
{
    vector<string> v;
    string word;
    for (int i = 0; i <= text.size(); ++i)
    {
        if ((text[i] != ' ') && (text[i] != '\0'))
        {
            word += text[i];
        }
        else if (((text[i] == ' ') || (text[i] == '\0')) && (text[i - 1] != ' '))
        {
            if (word == ""s)
            {
                continue;
            }
            v.push_back(word);
            word = ""s;
        }
    }
    for (auto vec : v)
    {
        cout << '[' << vec << ']' << endl;
    }
    return v;
}




/*
Задание:
В прошлой теме вы усовершенствовали разбиение строки на слова: создали и заполнили вектор строк words. Теперь вынесите разбиение в отдельную функцию vector<string> SplitIntoWords(string text), которая принимает на вход строку и возвращает вектор слов.

Пример ввода-вывода:
В этой задаче стандартные потоки ввода и вывода использоваться не будут. Тренажёр вызовёт вашу функцию vector<string> SplitIntoWords(string text). В качестве аргумента будет передаваться строка из слов. Например, такая:

string str = "find me a cat"s; 

Вектор, возвращённый из функции, сравнится с ожидаемым вектором. В этом примере ожидаемый вектор такой:

vector<string> expected_result = {"find"s, "me"s, "a"s, "cat"s}; 

Как будет тестироваться ваш код:
Тренажёр поэлементно сравнит возвращённый из функции вектор с ожидаемым. На экран ничего выводить не нужно.
*/




/*
Авторское решение:

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}


int main() {
    string query;
    getline(cin, query);
    
    for (string word : SplitIntoWords(query)) {
        cout << '[' << word << ']' << endl;
    }

    return 0;
}

*/