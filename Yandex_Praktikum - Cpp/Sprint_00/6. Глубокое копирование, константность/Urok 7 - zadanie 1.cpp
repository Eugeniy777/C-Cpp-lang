#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string ReadLine()
{
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber()
{
    int result = 0;
    cin >> result;
    ReadLine();		//надо разобраться
    return result;
}

/*  строку, переданную по константной ссылке разбивает на сслова и вставляет в вектор */
vector<string> SplitIntoWords(const string &text)
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

/*  принимает строку стоп-слов по константной ссылке,
    разбивает её на слова, с помощью SplitIntoWords(),
    записывает слова в множиство стоп-слов */
set<string> ParseStopWords(const string &text)
{
    set<string> stop_words;
    for (const string &word : SplitIntoWords(text))
    {
        stop_words.insert(word);
    }
    return stop_words;
}

/*  принимает множество стоп-слов и строку запроса по константной ссылке,
    разбивает строку на слова с помощью SplitIntoWords(),
    вставляет слова в вектор документа */
vector<string> SplitIntoWordsNoStop(const string &text, const set<string> &stop_words)
{
    // создаём вектор для заполнения "чистыми" словами
    vector<string> words;
    // проходим по всем словам из текста и проверяем, что их нет в списке стоп-слов
    for (const string &word : SplitIntoWords(text))
    {
        if (stop_words.count(word) == 0)
        {
            words.push_back(word);
        }
    }
    // вернём результат без стоп-слов
    return words;
}

/*  принимает "базу документов" (вектор векторов) по ссылке,
    принимает множество стоп-слов и строку запроса по константной ссылке,
    "очищает" новые документы от стоп-слов с помощью SplitIntoWordsNoStop(),
    вставляет слова в "базу документов" */
void AddDocument(vector<vector<string>> &documents, const set<string> &stop_words, const string &document)
{
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.push_back(words);
}

/*  принимает множество стоп-слов и строку запроса по константной ссылке,
    разбивает строку на слова с помощью SplitIntoWords(),
    вставляет слова в новое множество "чистых" слов */
set<string> ParseQuery(const string &text, const set<string> &stop_words)
{
    set<string> query_words;
    for (const string &word : SplitIntoWords(text))
    {
        if (stop_words.count(word) == 0)
        {
            query_words.insert(word);
        }
    }
    // вернём результат без стоп-слов
    return query_words;
}

// Возвращает true, если среди слов документа (document_words)
// встречаются слова поискового запроса query_words
bool MatchDocument(const vector<string> &document_words, const set<string> &query_words)
{
    for (auto word : document_words)
    {
        if (query_words.count(word))
        {
            return true;
        }
    }
    return false;
}

// Возвращает массив id документов, подходящих под запрос query
// Стоп-слова исключаются из поиска
vector<int> FindDocuments(const vector<vector<string>> &documents, const set<string> &stop_words,
                          const string &query)
{
    vector<int> matched_documents;
    set<string> parsed_query = ParseQuery(query, stop_words);
    /*
    for (int i = 0; i < documents.size(); ++i)
    {
        if (MatchDocument(documents[i], parsed_query))
        {
            matched_documents.push_back(i);
        }
    }
    */
    int id = 0;
    for (const auto &document : documents)
    {
        if (MatchDocument(document, parsed_query))
        {
            matched_documents.push_back(id);
        }
        ++id;
        // Внутри цикла document имеет тип const vector<string>&
        // document - это строка "базы данных"
        // parsed_query - это "чистый" поисковый запрос
    }
    return matched_documents;
}

int main()
{
    // создали и заполнили строку стоп-слов
    const string stop_words_joined = ReadLine();
    // поместили строку слов в множество стоп-слов
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // создали "базу данных"
    vector<vector<string>> documents;
    // указали размер "базы данных"
    const int document_count = ReadLineWithNumber();
    // заполнили базу данных (сразу без стоп-слов)
    for (int document_id = 0; document_id < document_count; ++document_id)
    {
        AddDocument(documents, stop_words, ReadLine());
    }

    // создали и заполнили поисковую строку
    const string query = ReadLine();

    // поиск в "базе данных" номеров строк, содержащих слова из поисковой строки
    for (const int document_id : FindDocuments(documents, stop_words, query))
    {
        cout << "{ document_id = "s << document_id << " }"s << endl;
    }
    return 0;
}





/*
Напишите реализацию поиска по базе документов. Используйте следующий алгоритм:

    * Взять очередной документ из базы документов. Вы уже знаете, что это вектор слов документа.
    * Добавить индекс документа в результаты поиска, если среди слов этого документа встречаются слова из поискового запроса.
    * Повторить эти действия для оставшихся документов.

Так как в базе документов не содержатся стоп-слова, лучше сразу исключить их из поискового запроса.


Функция main из заготовки кода считывает стоп-слова, документы и поисковый запрос.
Затем она выводит результаты поиска: id документов, соответствующих поисковому запросу.

Требования:
Разные слова могут встречаться в одних и тех же документах. Верните результат поиска без повторов.
Не меняйте сигнатуру FindDocuments.
Пример использования функций


Формат ввода и вывода:
В первой строке ввода содержатся стоп-слова, разделённые пробелами. Следующая строка ввода содержит целое число N, задающее количество документов.
В каждой из последующих N строк — текст документа, в котором слова разделяются одним пробелом. Последняя строка ввода содержит текст поискового запроса, где слова разделяются одним пробелом.
Программа должна вывести id документов, соответствующих поисковому запросу, как это показано ниже. id выводятся в порядке возрастания.

Пример ввода:

a an on the in is has been are with for from have be was
4
a small curly guinea pig with grey hair has been found
a young 50 year old crocodile wants to make friends
a strange brown creature was seen in the box of oranges
a strange animal with big ears is building a house for its friends
cheburashka with big ears likes oranges

Пример вывода:

{ document_id = 2 }
{ document_id = 3 }

Под запрос "cheburashka with big ears likes oranges" подходят два документа:

    Документ "a strange brown creature was seen in the box of oranges" с id=2
    Документ "a strange animal with big ears is building a house for its friends" с id=3

Слово "with" — стоп-слово. Оно не участвует в поиске. Поэтому документ "a small curly guinea pig with grey hair has been found" не будет найден.

*/




/*
Решение от авторов:

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}

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

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(vector<vector<string>>& documents, const set<string>& stop_words,
                 const string& document) {
    const vector<string> words = SplitIntoWordsNoStop(document, stop_words);
    documents.push_back(words);
}

set<string> ParseQuery(const string& text, const set<string>& stop_words) {
    set<string> query_words;
    for (const string& word : SplitIntoWordsNoStop(text, stop_words)) {
        query_words.insert(word);
    }
    return query_words;
}

bool MatchDocument(const vector<string>& document_words, const set<string>& query_words) {
    for (const string& word : document_words) {
        if (query_words.count(word) != 0) {
            return true;
        }
    }
    return false;
}

// Для каждого найденного документа возвращает его id
vector<int> FindDocuments(const vector<vector<string>>& documents, const set<string>& stop_words,
                          const string& query) {
    const set<string> query_words = ParseQuery(query, stop_words);
    vector<int> matched_documents;
    int document_id = 0;
    for (const auto& document : documents) {
        if (MatchDocument(document, query_words)) {
            matched_documents.push_back(document_id);
        }
        ++document_id;
    }
    return matched_documents;
}

int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    vector<vector<string>> documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, ReadLine());
    }

    const string query = ReadLine();
    for (const int document_id : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << " }"s << endl;
    }
}

*/