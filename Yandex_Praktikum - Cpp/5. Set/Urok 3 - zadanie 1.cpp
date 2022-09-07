#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int CalculateSimilarity(vector<string> first, vector<string> second)
{
    // верните размер пересечения множеств слов first и second
    set<string> one;
    set<string> two;
    for (auto word : first)
    {
        one.insert(word);
    }
    for (auto word : second)
    {
        two.insert(word);
    }
    int counter = 0;
    for (auto word : one)
    {
        for (auto word2 : two)
        {
            if (word == word2)
            {
                ++counter;
            }
        }
    }
    return counter;
}

// SplitIntoWords разбивает строку text на слова и возвращает их в виде вектора
// Слово - последовательность непробельных символов,
// разделённых одним или более пробелов.
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
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;
}




/*
Задание 1
Представьте, что анализируете запросы пользователей в вашей поисковой системе. Есть слова запроса и описание животного. Посчитайте релевантность запроса — размер множества слов, которые входят и в запрос, и в описание. Для этого доработайте функцию CalculateSimilarity из заготовки кода так, чтобы она вернула релевантность.

Формат ввода:
Сначала вводится строка-запрос, затем с новой строчки строка-описание.

Формат вывода:
Выведите единственное целое число — размер пересечения множеств слов из запроса и описания.

Примеры:
Ввод:									Вывод:		Комментарий:
tiny cat \\ cat without tail						1		Слово cat
very kind dog with brown fur \\ dog with long tail			2		Слова dog и with
small starling \\ small black starling with small brown eyes		2		Слова small и starling

Как будет тестироваться ваш код:
Тренажёр проверит работу функции CalculateSimilarity. Для этого он вызовет её с разными векторами строк запросов и описаний животных и сравнит релевантность с ожидаемым значением. Не изменяйте типы параметров и возвращаемого значения этой функции, иначе она не пройдёт проверку.
Также тренажёр проверит корректность программы в целом. Ей на вход будут передаваться разные строки запросов запросов и описаний, а вывод программы будет сравниваться с ожидаемым. Не выводите никакой дополнительной информации в cout кроме релевантности запроса, иначе программа не пройдёт проверку.
*/




/*
Авторское решение:

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> MakeSet(vector<string> query_words) {
    set<string> s;
    for (string word : query_words) {
        s.insert(word);
    }
    return s;
}

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

int CalculateSimilarity(vector<string> first, vector<string> second) {
    set<string> first_set = MakeSet(first);
    set<string> second_set = MakeSet(second);
    set<string> intersection;
    for (string word : first_set) {
        if (second_set.count(word) > 0) {
            intersection.insert(word);
        }
    }
    return intersection.size();
}

int main() {
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;
}

*/