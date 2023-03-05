#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

// считываем строку
string ReadLine()
{
    string s;
    getline(cin, s);
    return s;
}

// считываем целочисл. число
int ReadLineWithNumber()
{
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}
// разбиваем строку на слова
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
        words.push_back(word);

    return words;
}

// структура для хранения идентификатора и релевантности документа
struct Document
{
    int id;
    double relevance;
};

class SearchServer
{
public:
// разбивает строку на множество стоп-слов
    void SetStopWords(const string &text)
    {
        for (const string &word : SplitIntoWords(text))
        {
            stop_words_.insert(word);
        }
    }
    // добавляет информацию о словах в документе в сервер
    void AddDocument(int document_id, const string &document)
    {
        ++document_count_;
        const double invert_word_count = 1. / SplitIntoWordsNoStop(document).size();
        for (const string &word : SplitIntoWordsNoStop(document))
        {
            word_to_document_freqs_[word][document_id] += invert_word_count;
        }
    }

    // возвращает вектор документов в порядке убывания релевантности
    vector<Document> FindTopDocuments(const string &raw_query) const
    {
        const Query query = ParseQuery(raw_query);
        auto matched_documents = FindAllDocuments(query);

        sort(matched_documents.begin(), matched_documents.end(),
             [](const Document &lhs, const Document &rhs)
             {
                 return lhs.relevance > rhs.relevance;
             });
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT)
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        return matched_documents;
    }

private:
    int document_count_ = 0;
    // сопоставляет каждому слову словарь «документ - TF»
    map<string, map<int, double>> word_to_document_freqs_;
    set<string> stop_words_;

    // разбивает строку на вектор слов и выкидывает стоп-слова
    vector<string> SplitIntoWordsNoStop(const string &text) const
    {
        vector<string> words;
        for (const string &word : SplitIntoWords(text))
        {
            if (stop_words_.count(word) == 0)
                words.push_back(word);
        }
        return words;
    }
    struct QueryWord
    {
        string data;
        bool is_minus;
        bool is_stop;
    };

    // проверяет на минус-слова
    QueryWord ParseQueryWord(string text) const
    {
        bool is_minus = false;
        // если первый символ "-", то значит минус-слово
        if (text[0] == '-')
        {
            is_minus = true;
            text = text.substr(1);
        }
        return {text, is_minus, {stop_words_.count(text) > 0}};
    }

    struct Query
    {
        set<string> plus_words;
        set<string> minus_words;
    };

    // заполняет структуру плюс- и минус-словами
    Query ParseQuery(const string &text) const
    {
        Query query;
        for (const string &word : SplitIntoWords(text))
        {
            const QueryWord query_word = ParseQueryWord(word);
            if (!query_word.is_stop)
            {
                if (query_word.is_minus)
                {
                    query.minus_words.insert(query_word.data);
                }
                else
                {
                    query.plus_words.insert(query_word.data);
                }
            }
        }
        return query;
    }

    // по строке запроса находит все пары документов с наличием релевантности
    vector<Document> FindAllDocuments(const Query &query) const
    {
        map<int, double> rel_doc;
        for (const auto &word : query.plus_words)
        {
            if (word_to_document_freqs_.count(word) == 0)
            {
                continue;
            }
            const double idf = log(document_count_ * 1. / word_to_document_freqs_.at(word).size());
            for (const auto [document_id, tf] : word_to_document_freqs_.at(word))
            {
                rel_doc[document_id] += idf * tf;
            }
        }

        for (const string &word : query.minus_words)
        {
            if (word_to_document_freqs_.count(word) == 0)
            {
                continue;
            }
            for (const auto [document_id, m] : word_to_document_freqs_.at(word))
            {
                rel_doc.erase(document_id);
            }
        }

        // вектор структур (идентификатор - релевантность)
        vector<Document> matched_documents;
        for (const auto [document_id, relevance] : rel_doc)
        {
            matched_documents.push_back({document_id, relevance});
        }
        return matched_documents;
    }
};

// функция для создания "документов" (строк, по которым происходит поиск)
SearchServer CreateSearchServer()
{
    SearchServer search_server;
    search_server.SetStopWords(ReadLine());

    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id)
    {
        search_server.AddDocument(document_id, ReadLine());
    }

    return search_server;
}

int main()
{
    const SearchServer search_server = CreateSearchServer();

    const string query = ReadLine();
    for (const auto &[document_id, relevance] : search_server.FindTopDocuments(query))
    {
        cout << "{ document_id = "s << document_id << ", "
             << "relevance = "s << relevance << " }"s << endl;
    }
}




/*
Задание 1


Переведите вычисление релевантности на формулу TF-IDF.
Будьте внимательны с повторами: теперь они важны и кратно увеличивают релевантность по соответствующему слову. Повторение слова в документе увеличивает TF. Сколько раз слово повторится в документе, столько раз нужно будет перемножить TF и IDF этого слова.
Чтобы вычислить IDF, в поисковой системе должно храниться количество документов. Для этого заведите в классе поле document_count_ типа int и по умолчанию проинициализируйте нулём при объявлении: int document_count_ = 0;.
Измените у поля relevance структуры Document тип с int на double. Теперь релевантность — вещественное число, вычисляемое по формуле TF-IDF.
Как будет тестироваться ваша программа
Тренажёр передаст вашей программе входные данные через стандартный поток ввода и сравнит результат её работы с ожидаемым.
Чтобы измерить эффективность поиска, тренажёр заменит вашу функцию main на нашу. В ней будет создан экземпляр класса SearchServer, в который добавятся десятки тысяч документов. Документы содержат от 10 до 100 слов.
При добавлении будет измеряться время поиска по базе документов. У вас в коде есть инвертированный индекс, поэтому поиск среди десятков тысяч документов не должен требовать намного больше времени, чем поиск среди сотен.
Пример входных и выходных данных
Ввод

is are was a an in the with near at
3
a colorful parrot with green wings and red tail is lost
a grey hound with black ears is found at the railway station
a white cat with long furry tail is found near the red square
white cat long tail 

Вывод

{ document_id = 2, relevance = 0.462663 }
{ document_id = 0, relevance = 0.0506831 } 

Комментарий
В C++ вещественные числа типа double отображаются с точностью до шести знаков после запятой, а не до четырёх, как мы считали в теоретической части урока.
*/




/*
// Решение от авторов:


#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
const int MAX_RESULT_DOCUMENT_COUNT = 5;
 
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
 
struct Document {
    int id;
    double relevance;
};
 
class SearchServer {
public:
    void SetStopWords(const string& text) {
        for (const string& word : SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }
 
    void AddDocument(int document_id, const string& document) {
        ++document_count_;
        const vector<string> words = SplitIntoWordsNoStop(document);
        const double inv_word_count = 1.0 / words.size();
        for (const string& word : words) {
            word_to_document_freqs_[word][document_id] += inv_word_count;
        }
    }
 
    vector<Document> FindTopDocuments(const string& raw_query) const {
        const Query query = ParseQuery(raw_query);
        auto matched_documents = FindAllDocuments(query);
 
        sort(matched_documents.begin(), matched_documents.end(),
             [](const Document& lhs, const Document& rhs) {
                 return lhs.relevance > rhs.relevance;
             });
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        return matched_documents;
    }
 
private:
    struct QueryWord {
        string data;
        bool is_minus;
        bool is_stop;
    };
 
    struct Query {
        set<string> plus_words;
        set<string> minus_words;
    };
 
    int document_count_ = 0;
    set<string> stop_words_;
    map<string, map<int, double>> word_to_document_freqs_;
 
    bool IsStopWord(const string& word) const {
        return stop_words_.count(word) > 0;
    }
 
    vector<string> SplitIntoWordsNoStop(const string& text) const {
        vector<string> words;
        for (const string& word : SplitIntoWords(text)) {
            if (!IsStopWord(word)) {
                words.push_back(word);
            }
        }
        return words;
    }
 
    QueryWord ParseQueryWord(string text) const {
        bool is_minus = false;
        // Word shouldn't be empty
        if (text[0] == '-') {
            is_minus = true;
            text = text.substr(1);
        }
        return {text, is_minus, IsStopWord(text)};
    }
 
    Query ParseQuery(const string& text) const {
        Query query;
        for (const string& word : SplitIntoWords(text)) {
            const QueryWord query_word = ParseQueryWord(word);
            if (!query_word.is_stop) {
                if (query_word.is_minus) {
                    query.minus_words.insert(query_word.data);
                } else {
                    query.plus_words.insert(query_word.data);
                }
            }
        }
        return query;
    }
 
    double ComputeWordInverseDocumentFreq(const string& word) const {
        return log(document_count_ * 1.0 / word_to_document_freqs_.at(word).size());
    }
 
    vector<Document> FindAllDocuments(const Query& query) const {
        map<int, double> document_to_relevance;
        for (const string& word : query.plus_words) {
            if (word_to_document_freqs_.count(word) == 0) {
                continue;
            }
            const double inverse_document_freq = ComputeWordInverseDocumentFreq(word);
            for (const auto [document_id, term_freq] : word_to_document_freqs_.at(word)) {
                document_to_relevance[document_id] += term_freq * inverse_document_freq;
            }
        }
 
        for (const string& word : query.minus_words) {
            if (word_to_document_freqs_.count(word) == 0) {
                continue;
            }
            for (const auto [document_id, _] : word_to_document_freqs_.at(word)) {
                document_to_relevance.erase(document_id);
            }
        }
 
        vector<Document> matched_documents;
        for (const auto [document_id, relevance] : document_to_relevance) {
            matched_documents.push_back({document_id, relevance});
        }
        return matched_documents;
    }
};
 
SearchServer CreateSearchServer() {
    SearchServer search_server;
    search_server.SetStopWords(ReadLine());
 
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        search_server.AddDocument(document_id, ReadLine());
    }
 
    return search_server;
}
 
int main() {
    const SearchServer search_server = CreateSearchServer();
 
    const string query = ReadLine();
    for (const auto& [document_id, relevance] : search_server.FindTopDocuments(query)) {
        cout << "{ document_id = "s << document_id << ", "
             << "relevance = "s << relevance << " }"s << endl;
    }
}
*/