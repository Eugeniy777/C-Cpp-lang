#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> SetSplitIntoWords(string text)
{
    set<string> words;
    string word;
    for (const char c : text)
    {
        if (c == ' ')
        {
            if (!word.empty())
            {
                words.insert(word);
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
    {
        words.insert(word);
    }

    return words;
}

vector<string> SplitIntoWords(string text)
{
    vector<string> words;
    string word;
    for (const char c : text)
    {
        if (c == ' ')
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }

    return words;
}

int main()
{
    /* Считайте строку со стоп-словами */
    string stop_words;
    getline(cin, stop_words);
    set<string> stop_wo = SetSplitIntoWords(stop_words);
    // Считываем строку-запрос
    string query;
    getline(cin, query);

    // Выведите только те слова, которых нет среди стоп-слов
    for (string word : SplitIntoWords(query))
    {
        if (!stop_wo.count(word))
            cout << '[' << word << ']' << endl;
    }
return 0;
}




/*
Задание:
Научите свою поисковую систему отбрасывать стоп-слова. Для этого напишите программу, которая считывает стоп-слова и строку-запрос и выводит те слова запроса, которых нет среди запрещённых.
Формат вывода слов оставьте как в заготовке кода. Функция разбиения строки на слова у вас уже реализована, осталось сделать фильтрацию.

Формат входных и выходных данных:
Первая строка ввода содержит стоп-слова, разделённые пробелом. Вторая строка содержит поисковый запрос.
Программа должна вывести слова поискового запроса, которых нет среди стоп-слов. Каждое слово, прошедшее проверку, выводится в отдельной строке внутри символов [ и ]. Слова должны выводиться в том же порядке, в каком они были в строке запроса.

Ввод:

with many very
very kind dog with brown fur with long long tail 

Вывод:

[kind]
[dog]
[brown]
[fur]
[long]
[long]
[tail] 
*/




/*
Авторское решение:
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (const char c : text) {
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

set<string> ParseStopWords(string text) {
    set<string> stop_words;
    for (string word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(string text, set<string> stop_words) {
    vector<string> words;
    for (string word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}


int main() {
    // Read stop words
    string stop_words_joined;
    getline(cin, stop_words_joined);
    set<string> stop_words = ParseStopWords(stop_words_joined);
    
    // Read query
    string query;
    getline(cin, query);
    vector<string> query_words = ParseQuery(query, stop_words);
    
    for (string word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}

*/