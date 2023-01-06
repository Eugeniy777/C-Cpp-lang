#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// разбивает предложение на слова и записывает в вектор
vector<string> SplitIntoWords(const string& text) {
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

/* с помощью функции SplitIntoWords (разбивающей предложение на слова и записывающей их в вектор) присваивает слова из вектора в множество стоп-слов */
set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

/* сравнивает исходные слова, присвоенные в вектор(с помощью функции SplitIntoWords) с множеством стоп-слов и записывает очищенное от стоп слов предложение в вектор */
vector<string> ParseQuery(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
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
    
    for (const string& word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}




/*
Задание:

Посмотрите на код программы, которая обрабатывает поисковый запрос. Отметьте константными все ссылки, которые должны ими быть. Попробуйте изменить объекты по полученным константным ссылкам. Сообщение об ошибке будет выглядеть знакомо.

Формат входных и выходных данных:
Программе на вход подаются две строки. В первой строке содержатся разделяемые пробелами стоп-слова. Во второй строке содержится поисковый запрос. Программа должна вывести каждое слово запроса внутри фигурных скобок, по одному слову в строке. Слова запроса, входящие в множество стоп-слов, выводиться не должны.

Примеры входных и выходных данных

Ввод:

a with many is are was near very 
a small red cat was found near railway station 

Вывод:

[small]
[red]
[cat]
[found]
[railway]
[station] 

Как будет тестироваться ваш код:
Тренажёр подаст на вход программы различные варианты входных данных и проверит, что выходные данные соответствуют ожидаемым значениям. Также тренажёр проверит, что функции программы принимают параметры по константной ссылке.
Не добавляйте, не переименовывайте и не удаляйте функции программы, а также не переименовывайте аргументы функций. Иначе код может не пройти проверки.
*/