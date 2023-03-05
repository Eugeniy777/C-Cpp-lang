#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
const int MAX_RESULT_DOCUMENT_COUNT = 5;
 
 
/* определяем функцию считывания строки
 * возвращает строку */
string ReadLine() {
    /* объявляем строку */
    string s;
    /* считываем строку целиком в переменную */
    getline(cin, s);
    /* возвращаем переменную */
    return s;
}
 
/* определяем функцию для считывания переменной int и строки
 * возвращает считанную переменную int */
int ReadLineWithNumber() {
    /* объявляем переменную */
    int result;
    /* считываем переменную */
    cin >> result;
    /* вызываем функцию ReadLine */
    ReadLine();
    /* возвращаем переменную */
    return result;
}
 
/* определяем функцию для разбиения строки на слова
 * принимает константную ссылку на строку text
 * возвращает вектор слов составленный из слов в строке text */
vector<string> SplitIntoWords(const string& text) {
    /* объявляем вектор строк для хранения слов */
    vector<string> words;
    /* объявляем строку для хранения слова */
    string word;
    /* проходим посимвольно (char c) по всей строке */
    for (const char c : text) {
        /* условие на выполнение блока:
         * * символ это пробел */
        if (c == ' ') {
            /* добавляем слово в конец вектора слов */
            words.push_back(word);
            /* присваиваем переменной пустую строку, т.е. начинаем новое слово */
            word = ""s;
            /* условие на выполнение блока обратное условие:
             * * символ это не пробел */
        } else {
            /* добавляем символ к строке.
             * Этим блоком мы собираем слово в переменной word */
            word += c;
        }
    }
    /* добавляем слово в конец вектора слов */
    words.push_back(word);
 
    /* возвращаем вектор слов */
    return words;
}
 
 
/* определяем структуру для хранения информации о документе */
struct Document {
    /* объявляем идентификатор документа */
    int id;
    /* объявляем релевантность документа */
    int relevance;
};
 
 
/* определяем функцию для определения больше ли релевантность одного документа, чем у другого
 * принимает константную ссылку на структуру Document lhs
 * * * * * * константную ссылку на структуру Document rhs
 * возвращает bool значение */
bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
    /* возвращаем больше ли релевантность одного документа, чем у другого */
    return lhs.relevance > rhs.relevance;
}
 
 
/* определяем класс поискового сервера */
class SearchServer {
public:
    /* определяем метод для разбиения строки на множество "стоп-слов"
     * принимает константную ссылку на строку text */
    void SetStopWords(const string& text) {
        /* проходим по всем словам вектора возвращённого функцией SplitIntoWords */
        for (const string& word : SplitIntoWords(text)) {
            /* добавляем слово во множество слов */
            stop_words_.insert(word);
        }
    }
 
    /* определяем метод для добавления информации о словах в документе document в сервер
     * принимает переменную int document_id содержащую идентификатор документа,
     * * * * * * константную ссылку на строку document, содержащую документ */
    void AddDocument(int document_id, const string& document) {
        /* проходим по всем словам вектора возвращённого функцией SplitIntoWordsNoStop */
        for (const string& word : SplitIntoWordsNoStop(document)) {
            /* добавляем document_id во множество из пары, ключом которой является слово word */
            word_to_documents_[word].insert(document_id);
        }
    }
 
 
    /* определяем функцию для всех слов из запроса query возвращает в порядке убывания релевантности (не более MAX_RESULT_DOCUMENT_COUNT) пары документов и значений релевантности, релевантные запросу
     * принимает константную ссылку на строку запроса
     * возвращает вектор структур Document состоящий из найденных идентификаторов документов и релевантности */
    vector<Document> FindTopDocuments(const string& query) const /* FOR SUPPORT: добавлен const */ {
        /* объявляем вектор пар состоящий из найденных идентификаторов документов и релевантности и инициализируем результатом функции FindAllDocuments */
        auto matched_documents = FindAllDocuments(query);
 
        /* сортируем вектор с помощью параллельного алгоритма из стандартной библиотеки
         * передаем в sort 3-им параметром функцию-компаратор */
        sort(matched_documents.begin(), matched_documents.end(), HasDocumentGreaterRelevance);
        /* условие на выполнение блока:
         * * размер вектора больше MAX_RESULT_DOCUMENT_COUNT */
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            /* уменьшаем размер вектора до MAX_RESULT_DOCUMENT_COUNT */
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        /* возвращаем вектор структур Document */
        return matched_documents;
    }
 
private:
    /* объявляем словарь пар строк и множеств чисел для хранения  */
    map<string, set<int>> word_to_documents_;
    /* объявляем множество для хранения "стоп-слов" */
    set<string> stop_words_;
 
    /* определяем метод для разбиения строки text на слова, без учёта "стоп-слов"
     * принимает константную ссылку на строку text
     * возвращает вектор слов составленный из слов в строке text но которых нет во множестве "стоп-слов" */
    vector<string> SplitIntoWordsNoStop(const string& text) const /* FOR SUPPORT: добавлен const */ {
        /* объявляем вектор строк для хранения слов */
        vector<string> words;
        /* проходим по всем словам вектора возвращённого функцией SplitIntoWords */
        for (const string& word : SplitIntoWords(text)) {
            /* условие на выполнение блока:
             * * число вхождений word во множество stop_words равно 0, т.е. множество stop_words не содержит word */
            if (stop_words_.count(word) == 0) {
                /* добавляем слово в конец вектора слов */
                words.push_back(word);
            }
        }
        /* возвращаем вектор слов */
        return words;
    }
 
    /* определяем функцию для всех слов из запроса query возвращает все пары документов и значений релевантности, релевантные запросу
     * принимает константную ссылку на строку запроса
     * возвращает вектор структур Document состоящий из найденных идентификаторов документов и релевантности */
    vector<Document> FindAllDocuments(const string& query) const /* FOR SUPPORT: добавлен const */ {
        /* объявляем вектор строк для хранения слов из запроса без "стоп-слов" и инициализируем результатом функции SplitIntoWordsNoStop */
        const vector<string> query_words = SplitIntoWordsNoStop(query);
        /* объявляем словарь пар [переменная int, переменная int] для хранения пар [идентификатор документа, релевантность документа] */
        map<int, int> document_to_relevance;
        /* проходим по всем словам вектора query_words */
        for (const string& word : query_words) {
            /* условие на выполнение блока:
             * * число вхождений word во множество word_to_documents равно 0, т.е. множество word_to_documents не содержит word */
            if (word_to_documents_.count(word) == 0) {
                /* переходим к следующей итерации */
                continue;
            }
            /* проходим по всем идентификаторам вектора из пары, ключом которой является слово word */
            for (const int document_id : word_to_documents_.at(word)) {
                /* увеличиваем на единицу релевантность документа с идентификатором document_id */
                ++document_to_relevance[document_id];
            }
        }
 
        /* объявляем вектор пар для хранения пар идентификатор документа, релевантность документа */
        vector<Document> matched_documents;
        /* проходим по всем парам [document_id, relevance] словаря */
        for (auto [document_id, relevance] : document_to_relevance) {
            /* добавляем пару в конец вектора */
            matched_documents.push_back({document_id, relevance});
        }
        /* возвращаем вектор структур Document */
        return matched_documents;
    }
};
 
/* определяем функцию для создания поискового сервера с данными из стандартного входа */
SearchServer CreateSearchServer() {
    /* объявляем переменную */
    SearchServer search_server;
    /* вызываем метод SetStopWords и передаем в него то, что вернет функция ReadLine */
    search_server.SetStopWords(ReadLine());
 
    /* объявляем и инициализируем переменную значением которое вернет функция ReadLineWithNumber */
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        /* вызываем метод AddDocument и передаем в него идентификатор документа и
         * то, что вернет функция ReadLine (считываем из стандартного входа) */
        search_server.AddDocument(document_id, ReadLine());
    }
    /* возвращаем поисковый сервер */
    return search_server;
}
 
 
int main() {
    /* объявляем и инициализируем переменную значением которое вернет функция CreateSearchServer */
    const /* добавлен const */ SearchServer search_server = CreateSearchServer();
 
    const string query = ReadLine();
    /* проходим по всем парам [document_id, relevance] словаря возвращённого функцией FindTopDocuments */
    for (auto [document_id, relevance] : search_server.FindTopDocuments(query)) {
        /* выводим переменные в нужном формате */
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s << endl;
    }
}
*/