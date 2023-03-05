#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

struct Document
{
    int id;
    int rating;
};

void PrintDocuments(vector<Document> documents, size_t skip_start, size_t skip_finish)
{
    sort(documents.begin(), documents.end(), [](const Document &a, const Document &b)
         { return a.rating > b.rating; });
    if(documents.size() == 0){
        return;
    }
    else if(documents.size() < skip_finish){
        return;
    }
    for (size_t i = skip_start; i < documents.size() - skip_finish; ++i)
    {
        cout << "{ id = "s << documents[i].id << ", rating = "s << documents[i].rating << " }"s << endl;
    }
    // отсортировать документы и вывести не все
}

int main()
{
    PrintDocuments({{100, 5}, {101, 7}, {102, -4}, {103, 9}, {104, 1}}, 1, 2);

    return 0;
}




/*
Задание 1


Напишите функцию PrintDocuments, принимающую вектор документов и два числа: skip_start и skip_finish. Пусть функция сортирует документы по убыванию рейтинга и выводит документы в таком порядке, пропустив skip_start документов с наибольшим рейтингом и skip_finish с наименьшим. Считайте, что рейтинги не повторяются.
Числа на входе функции могут быть сколь угодно большими: ваша программа должна обрабатывать их корректно и не падать. Если требуется пропустить все документы или даже больше, не выводите ничего. Вектор документов может быть пустым, skip_start и skip_finish не обязательно меньше размера вектора. Формат вывода документов — в примере:

Пример

PrintDocuments(
    {
        {100, 5},
        {101, 7},
        {102, -4},
        {103, 9},
        {104, 1}
    },
    1,
    2
); 

Вывод

{ id = 101, rating = 7 }
{ id = 100, rating = 5 } 
*/




/*
// Решение от авторов:


#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
struct Document {
    int id;
    int rating;
};
 
void PrintDocuments(vector<Document> documents, size_t skip_start, size_t skip_finish) {
    if (documents.empty() || skip_start >= documents.size() || skip_finish >= documents.size()) {
        return;
    }
    sort(documents.begin(), documents.end(),
         [](const Document& lhs, const Document& rhs) { return lhs.rating > rhs.rating; });
    for (size_t i = skip_start; i + skip_finish < documents.size(); ++i) {
        cout << "{ id = "s << documents[i].id
             << ", rating = "s << documents[i].rating
             << " }"s << endl;
    }
}
 
int main() {
    PrintDocuments(
        {
            {100, 5},
            {101, 7},
            {102, -4},
            {103, 9},
            {104, 1}
        },
        1,
        2
    );
    return 0;
}
*/