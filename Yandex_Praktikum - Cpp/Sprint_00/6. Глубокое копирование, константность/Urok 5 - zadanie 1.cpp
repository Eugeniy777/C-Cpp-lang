#include <iostream>
#include <string>
#include <vector>

using namespace std;


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

int main() {
    for(string& au : SplitIntoWords("test search query"s))
    cout << '[' << au << ']' << ' ';
    return 0;
}




/*
Задание 1
Передайте в функцию SplitIntoWords текст "test search query" и выведите полученные слова в квадратных скобках.
*/