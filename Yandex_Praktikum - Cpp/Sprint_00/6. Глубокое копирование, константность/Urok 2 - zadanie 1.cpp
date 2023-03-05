#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// разбивает предложение на слова и записывает в вектор
vector<string> SplitIntoWords(string& text) {
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
set<string> ParseStopWords(string& text) {
    set<string> stop_words;
    for (string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

/* сравнивает исходные слова, присвоенные в вектор(с помощью функции SplitIntoWords) с множеством стоп-слов и записывает очищенное от стоп слов предложение в вектор */
vector<string> ParseQuery(string& text, set<string>& stop_words) {
    vector<string> words;
    for (string& word : SplitIntoWords(text)) {
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
    
    for (string& word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}




/*
Посмотрите на ранее написанный вами код, разбивающий текст на слова с учётом стоп-слов. Избавьтесь от лишних копирований в заголовках функций и в циклах for. Для этого допишите к типам амперсанды в нужных участках кода.
*/