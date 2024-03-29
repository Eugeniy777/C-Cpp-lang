#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Document
{
    int id;
    double relevance;
    int rating;
};

void SortDocuments(vector<Document> &matched_documents)
{
    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document &lhs, const Document &rhs)
         {
            if(lhs.rating == rhs.rating){
                return lhs.relevance > rhs.relevance;
            }
            else{
                return lhs.rating > rhs.rating;
            }
         });
}

int main()
{
    vector<Document> documents = {{100, 0.5, 4}, {101, 1.2, 4}, {102, 0.3, 5}};
    SortDocuments(documents);
    for (const Document &document : documents)
    {
        cout << document.id << ' ' << document.relevance << ' ' << document.rating << endl;
    }

    return 0;
}




/*
Задание 1


Вы сортировали найденные поисковой системой документы по убыванию релевантности. Не меняя данной функции, исправьте компаратор так, чтобы он сортировал по убыванию рейтинга. А при одинаковом рейтинге — по убыванию релевантности.

Код из тренажёра должен вывести следующее:

102 0.3 5
101 1.2 4
100 0.5 4 
*/




/*
// Решение от авторов:


#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
struct Document {
    int id;
    double relevance;
    int rating;
};
 
void SortDocuments(vector<Document>& matched_documents) {            
    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document& lhs, const Document& rhs) {
             return lhs.rating > rhs.rating
                 || (lhs.rating == rhs.rating
                     && lhs.relevance > rhs.relevance);
         });
}
 
int main() {
    vector<Document> documents = {
        {100, 0.5, 4},
        {101, 1.2, 4},
        {102, 0.3, 5}
    };
    SortDocuments(documents);
    for (const Document& document : documents) {
        cout << document.id << ' '
             << document.relevance << ' '
             << document.rating << endl;
    }
 
    return 0;
}
*/