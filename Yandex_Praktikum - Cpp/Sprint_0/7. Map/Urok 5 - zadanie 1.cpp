#include <iostream>
#include <set>
#include <string>
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
    ReadLine();
    return result;
}

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

set<string> ParseStopWords(const string &text)
{
    set<string> stop_words;
    for (const string &word : SplitIntoWords(text))
    {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string &text, const set<string> &stop_words)
{
    vector<string> words;
    for (const string &word : SplitIntoWords(text))
    {
        if (stop_words.count(word) == 0)
        {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(vector<pair<int, vector<string>>> &documents,
                 const set<string> &stop_words,
                 int document_id,
                 const string &document)
{
    const pair<int, vector<string>> document_id_and_document_words = {document_id, SplitIntoWordsNoStop(document, stop_words)};
    documents.push_back(document_id_and_document_words);
}

set<string> ParseQuery(const string &text, const set<string> &stop_words)
{
    set<string> query_words;
    for (const string &word : SplitIntoWordsNoStop(text, stop_words))
    {
        query_words.insert(word);
    }
    return query_words;
}

int MatchDocument(const pair<int, vector<string>> &content,
                  const set<string> &query_words)
{
    set<string> unique_words;
    vector<string> words = content.second;
    for (const auto &word : words)
    {
        if (query_words.count(word) != 0)
        {
            unique_words.insert(word);
        }
    }

    int relevance = unique_words.size();
    return relevance;
}
// Для каждого найденного документа возвращает его id
vector<pair<int, int>>
FindDocuments(const vector<pair<int, vector<string>>> &documents,
              const set<string> &stop_words,
              const string &query)
{
    const set<string> query_words = ParseQuery(query, stop_words);
    vector<pair<int, int>> matched_documents;
    for (const auto &document : documents)
    {
        int document_id = document.first;
        vector<string> doc_words = document.second;
        int doc_relevance = MatchDocument(document, query_words);
        if (doc_relevance > 0)
        {
            matched_documents.push_back({document_id, doc_relevance});
        }
    }
    return matched_documents;
}

int main()
{
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);
    // Read documents
    vector<pair<int, vector<string>>>
        documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id)
    {
        AddDocument(documents, stop_words, document_id, ReadLine());
    }
    const string query = ReadLine();
    for (auto [document_id, relevance] : FindDocuments(documents, stop_words, query))
    {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
             << endl;
    }
}




/*
Задание
Не всегда ответ на запрос соответствует ожиданиям. Чем результат ближе к ожидаемому, тем выше его релевантность запросу. Релевантностью документа называют количество уникальных слов, которые пересекаются с запросом. Научите свою поисковую систему считать релевантность документа.
Релевантность нужно возвращать вместе с идентификатором документа как пару из двух целых чисел {document_id, relevance}. Иными словами, функция FindDocuments теперь должна выглядеть так:

vector<pair<int, int>> FindDocuments(const vector<pair<int, vector<string>>>& documents,
                                     const set<string>& stop_words,
                                     const string& query) {
} 

Сама структура базы данных тоже должна измениться. Теперь каждый документ надо представить не в виде vector<string>, а в виде pair<int, vector<string>>. Первый элемент пары хранит id документа, а второй — вектор его слов. Функция AddDocument также должна изменить сигнатуру:

void AddDocument(vector<pair<int, vector<string>>>& documents,
                 const set<string>& stop_words,
                 int document_id, 
                 const string& document) {
} 

Вспомогательная функция MatchDocument раньше сообщала, соответствует ли документ поисковому запросу. Теперь она должна изменить сигнатуру и будет возвращать релевантность документа:

int MatchDocument(const pair<int, vector<string>>& content, 
                  const set<string>& query_words) {
} 

Пример
Запрос				Документ								Релевантность
cheburashka with big ears	a strange animal with big ears is building a house for its friends	2
grey guinea pig			a small curly guinea pig with grey hair has been found			3

Пример использования функций

int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Считываем документы
    vector<pair<int, vector<string>>> documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(documents, stop_words, document_id, ReadLine());
    }

    const string query = ReadLine();
    // Выводим результаты поиска по запросу query
    for (auto [document_id, relevance] : FindDocuments(documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s
             << endl;
    }
} 

Формат ввода и вывода
В первой строке ввода содержатся стоп-слова, разделённые пробелами. Во второй строке указывается целое число N. Оно задаёт количество документов. В каждой из следующих N строк — текст документа, в котором слова разделяются одним пробелом. Последняя строка ввода содержит текст поискового запроса, где слова разделяются одним пробелом.
Программа должна вывести id документов и их релевантность поисковому запросу, как показано ниже. Результаты выводятся в порядке добавления документов в базу данных.
Пример ввода:

a an on the in is has been are with for from have be was
4
a small curly guinea pig with grey hair has been found
a young 50 year old crocodile wants to make friends
a strange brown creature was seen in the box of oranges
a strange animal with big ears is building a house for its friends
cheburashka with big ears likes oranges 

Пример вывода:

{ document_id = 2, relevance = 1 }
{ document_id = 3, relevance = 2 } 

Под запрос “cheburashka with big ears likes oranges” подходят два документа:

    Документ “a strange brown creature was seen in the box of oranges” с id=2. Так как совпало только слово “oranges”, релевантность этого документа равна 1.
    Документ “a strange animal with big ears is building a house for its friends” с id=3. Его релевантность равна 2.

А “with” — стоп-слово. Оно не участвует в поиске. Поэтому документ “a small curly guinea pig with grey hair has been found” не будет найден.
*/