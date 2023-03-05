#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

string ReadLine()
{
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber()
{
    int result;
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
            words.push_back(word);
            word = ""s;
        }
        else
        {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}

struct Document
{
    int id;
    int relevance;
};

bool HasDocumentGreaterRelevance(const Document &lhs, const Document &rhs)
{
    return lhs.relevance > rhs.relevance;
}

class SearchServer
{
public:
    void SetStopWords(const string &text)
    {
        for (const string &word : SplitIntoWords(text))
        {
            stop_words_.insert(word);
        }
    }
    
    void AddDocument(int document_id, const string &document)
    {
        for (const string &word : SplitIntoWordsNoStop(document))
        {
            word_to_documents_[word].insert(document_id);
        }
    }

    vector<Document> FindTopDocuments(const string &query) const
    {
        auto matched_documents = FindAllDocuments(query);
        sort(matched_documents.begin(), matched_documents.end(), HasDocumentGreaterRelevance);
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT)
        {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        return matched_documents;
    }

private:
    map<string, set<int>> word_to_documents_;
    set<string> stop_words_;

    vector<string> SplitIntoWordsNoStop(const string &text) const
    {
        vector<string> words;
        for (const string &word : SplitIntoWords(text))
        {
            if (stop_words_.count(word) == 0)
            {
                words.push_back(word);
            }
        }
        return words;
    }

    vector<Document> FindAllDocuments(const string &query) const
    {
        const vector<string> query_words = SplitIntoWordsNoStop(query);
        map<int, int> document_to_relevance;
        for (const string &word : query_words)
        {
            if (word_to_documents_.count(word) == 0)
            {
                continue;
            }
            for (const int document_id : word_to_documents_.at(word))
            {
                ++document_to_relevance[document_id];
            }
        }

        vector<Document> matched_documents;
        for (auto [document_id, relevance] : document_to_relevance)
        {
            matched_documents.push_back({document_id, relevance});
        }
        return matched_documents;
    }
};

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
    for (auto [document_id, relevance] : search_server.FindTopDocuments(query))
    {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s << endl;
    }
}




/*
Задание 1


Внедрите в класс SearchServer поиск по инвертированному индексу документов из теории. Для этого внесите в класс следующие изменения:

    Удалите структуру DocumentContent — она вам больше не понадобится.
    Замените контейнер vector<DocumentContent> на контейнер map<string, set<int>>. Ключи этого контейнера — слова из добавленных документов, а значения — id документов, в которых это слово встречается.
    В методе AddDocument переберите слова документа, кроме стоп-слов. В множество документов, соответствующих очередному слову, вставьте id текущего документа.
    В методе FindAllDocuments сначала вычислите релевантность документов, в которые входят плюс-слова запроса. Для этого используйте map<int, int>, где ключ — id документа, а значение — количество плюс-слов, которые в этом документе встречаются. Затем исключите из получившегося map те документы, в которых встретилось хотя бы одно минус-слово. Оставшиеся элементы map скопируйте в результирующий vector<Document>.
    Возвращённый вектор документов будет отсортирован по убыванию релевантности в методе FindTopDocuments. Эта часть у вас уже реализована.

Функциональность программы в этом задании изменяться не должна. 
Формат ввода и вывода
В первой строке ввода содержатся стоп-слова, разделённые пробелами. Вторая строка ввода содержит целое число N, задающее количество документов. 
В каждой из последующих N строк — текст документа, в котором слова разделяются одним пробелом. Последняя строка ввода содержит текст поискового запроса, в котором слова разделяются одним пробелом.
Программа должна вывести id и релевантность пяти самых релевантных документов, отсортированных от наиболее релевантного к наименее релевантному, как это показано ниже.
Пример ввода:

is are was a an in the with near
3
a colorful parrot with green wings and red tail is lost
a grey hound with black ears is found at the railway station
a white cat with long furry tail is found near the red square
white cat long tail 

Пример вывода:

{ document_id = 2, relevance = 4 }
{ document_id = 0, relevance = 1 } 

Как будет тестироваться ваш код
Тренажёр передаст вашей программе входные данные через стандартный поток ввода и сравнит результат её работы с ожидаемым.
Чтобы измерить эффективность поиска, тренажёр заменит вашу функцию main на нашу. В ней будет создан экземпляр класса SearchServer, в который добавятся десятки тысяч документов. Документы содержат от 10 до 100 слов.
При добавлении будет измеряться время поиска по базе документов. У вас в коде есть инвертированный индекс, поэтому поиск среди десятков тысяч документов займёт не намного больше времени, чем поиск среди сотен.
*/




/*
// Решение от авторов:


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
string ReadLine()
{
    /* объявляем строку */
    string s;
    /* считываем строку целиком в переменную */
    getline(cin, s);
    /* возвращаем переменную */
    return s;
}

/* определяем функцию для считывания переменной int и строки
 * возвращает считанную переменную int */
int ReadLineWithNumber()
{
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
vector<string> SplitIntoWords(const string &text)
{
    /* объявляем вектор строк для хранения слов */
    vector<string> words;
    /* объявляем строку для хранения слова */
    string word;
    /* проходим посимвольно (char c) по всей строке */
    for (const char c : text)
    {
        /* условие на выполнение блока:
         * * символ это пробел */
        if (c == ' ')
        {
            /* добавляем слово в конец вектора слов */
            words.push_back(word);
            /* присваиваем переменной пустую строку, т.е. начинаем новое слово */
            word = ""s;
            /* условие на выполнение блока обратное условие:
             * * символ это не пробел */
        }
        else
        {
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
struct Document
{
    /* объявляем идентификатор документа */
    int id;
    /* объявляем релевантность документа */
    int relevance;
};

/* определяем функцию для определения больше ли релевантность одного документа, чем у другого
 * принимает константную ссылку на структуру Document lhs
 * * * * * * константную ссылку на структуру Document rhs
 * возвращает bool значение */
bool HasDocumentGreaterRelevance(const Document &lhs, const Document &rhs)
{
    /* возвращаем больше ли релевантность одного документа, чем у другого */
    return lhs.relevance > rhs.relevance;
}

/* определяем класс поискового сервера */
class SearchServer
{
public:
    /* определяем метод для разбиения строки на множество "стоп-слов"
     * принимает константную ссылку на строку text */
    void SetStopWords(const string &text)
    {
        /* проходим по всем словам вектора возвращённого функцией SplitIntoWords */
        for (const string &word : SplitIntoWords(text))
        {
            /* добавляем слово во множество слов */
            stop_words_.insert(word);
        }
    }

    /* определяем метод для добавления информации о словах в документе document в сервер
     * принимает переменную int document_id содержащую идентификатор документа,
     * * * * * * константную ссылку на строку document, содержащую документ */
    void AddDocument(int document_id, const string &document)
    {
        /* проходим по всем словам вектора возвращённого функцией SplitIntoWordsNoStop */
        for (const string &word : SplitIntoWordsNoStop(document))
        {
            /* добавляем document_id во множество из пары, ключом которой является слово word */
            word_to_documents_[word].insert(document_id);
        }
    }

    /* определяем функцию для всех слов из запроса query возвращает в порядке убывания релевантности (не более MAX_RESULT_DOCUMENT_COUNT) пары документов и значений релевантности, релевантные запросу
     * принимает константную ссылку на строку запроса
     * возвращает вектор структур Document состоящий из найденных идентификаторов документов и релевантности */
    vector<Document> FindTopDocuments(const string &query) const /* FOR SUPPORT: добавлен const */
    {
        /* объявляем вектор пар состоящий из найденных идентификаторов документов и релевантности и инициализируем результатом функции FindAllDocuments */
        auto matched_documents = FindAllDocuments(query);

        /* сортируем вектор с помощью параллельного алгоритма из стандартной библиотеки
         * передаем в sort 3-им параметром функцию-компаратор */
        sort(matched_documents.begin(), matched_documents.end(), HasDocumentGreaterRelevance);
        /* условие на выполнение блока:
         * * размер вектора больше MAX_RESULT_DOCUMENT_COUNT */
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT)
        {
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
    vector<string> SplitIntoWordsNoStop(const string &text) const /* FOR SUPPORT: добавлен const */
    {
        /* объявляем вектор строк для хранения слов */
        vector<string> words;
        /* проходим по всем словам вектора возвращённого функцией SplitIntoWords */
        for (const string &word : SplitIntoWords(text))
        {
            /* условие на выполнение блока:
             * * число вхождений word во множество stop_words равно 0, т.е. множество stop_words не содержит word */
            if (stop_words_.count(word) == 0)
            {
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
    vector<Document> FindAllDocuments(const string &query) const /* FOR SUPPORT: добавлен const */
    {
        /* объявляем вектор строк для хранения слов из запроса без "стоп-слов" и инициализируем результатом функции SplitIntoWordsNoStop */
        const vector<string> query_words = SplitIntoWordsNoStop(query);
        /* объявляем словарь пар [переменная int, переменная int] для хранения пар [идентификатор документа, релевантность документа] */
        map<int, int> document_to_relevance;
        /* проходим по всем словам вектора query_words */
        for (const string &word : query_words)
        {
            /* условие на выполнение блока:
             * * число вхождений word во множество word_to_documents равно 0, т.е. множество word_to_documents не содержит word */
            if (word_to_documents_.count(word) == 0)
            {
                /* переходим к следующей итерации */
                continue;
            }
            /* проходим по всем идентификаторам вектора из пары, ключом которой является слово word */
            for (const int document_id : word_to_documents_.at(word))
            {
                /* увеличиваем на единицу релевантность документа с идентификатором document_id */
                ++document_to_relevance[document_id];
            }
        }

        /* объявляем вектор пар для хранения пар идентификатор документа, релевантность документа */
        vector<Document> matched_documents;
        /* проходим по всем парам [document_id, relevance] словаря */
        for (auto [document_id, relevance] : document_to_relevance)
        {
            /* добавляем пару в конец вектора */
            matched_documents.push_back({document_id, relevance});
        }
        /* возвращаем вектор структур Document */
        return matched_documents;
    }
};

/* определяем функцию для создания поискового сервера с данными из стандартного входа */
SearchServer CreateSearchServer()
{
    /* объявляем переменную */
    SearchServer search_server;
    /* вызываем метод SetStopWords и передаем в него то, что вернет функция ReadLine */
    search_server.SetStopWords(ReadLine());

    /* объявляем и инициализируем переменную значением которое вернет функция ReadLineWithNumber */
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id)
    {
        /* вызываем метод AddDocument и передаем в него идентификатор документа и
         * то, что вернет функция ReadLine (считываем из стандартного входа) */
        search_server.AddDocument(document_id, ReadLine());
    }
    /* возвращаем поисковый сервер */
    return search_server;
}

int main()
{
    /* объявляем и инициализируем переменную значением которое вернет функция CreateSearchServer */
    const /* добавлен const */ SearchServer search_server = CreateSearchServer();

    const string query = ReadLine();
    /* проходим по всем парам [document_id, relevance] словаря возвращённого функцией FindTopDocuments */
    for (auto [document_id, relevance] : search_server.FindTopDocuments(query))
    {
        /* выводим переменные в нужном формате */
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s << endl;
    }
}
*/