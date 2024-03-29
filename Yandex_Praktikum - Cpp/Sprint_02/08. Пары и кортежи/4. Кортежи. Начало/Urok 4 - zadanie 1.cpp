#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum class Status
{
    ACTUAL,
    EXPIRED,
    DELETED
};

struct Document
{
    int id;
    Status status;
    double relevance;
    int rating;
};

void SortDocuments(vector<Document> &matched_documents)
{
    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document &lhs, const Document &rhs)
         {
            return tuple(lhs.status, lhs.rating * -1, lhs.relevance * -1.0) < tuple(rhs.status, rhs.rating * -1, rhs.relevance * -1.0);
         });
}

int main()
{
    vector<Document> documents = {
        {100, Status::ACTUAL, 0.5, 4},
        {101, Status::EXPIRED, 0.5, 4},
        {102, Status::ACTUAL, 1.2, 4},
        {103, Status::DELETED, 1.2, 4},
        {104, Status::ACTUAL, 0.3, 5},
    };
    SortDocuments(documents);
    for (const Document &document : documents)
    {
        cout << document.id << ' ' << static_cast<int>(document.status) << ' ' << document.relevance
             << ' ' << document.rating << endl;
    }

    return 0;
}




/*
Задание 1


Перепишите компаратор из предыдущего урока, применив кортежи.
Код должен вывести следующее:

104 0 0.3 5
102 0 1.2 4
100 0 0.5 4
101 1 0.5 4
103 2 1.2 4 
*/




/*
// Решение от авторов:


#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
 
using namespace std;
 
enum class Status {
    ACTUAL,
    EXPIRED,
    DELETED
};
 
struct Document {
    int id;
    Status status;
    double relevance;
    int rating;
};
 
void SortDocuments(vector<Document>& matched_documents) {            
    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document& lhs, const Document& rhs) {
             return tuple(lhs.status, -lhs.rating, -lhs.relevance)
                    < tuple(rhs.status, -rhs.rating, -rhs.relevance);
         });
}
 
int main() {
    vector<Document> documents = {
        {100, Status::ACTUAL,  0.5, 4},
        {101, Status::EXPIRED, 0.5, 4},
        {102, Status::ACTUAL,  1.2, 4},
        {103, Status::DELETED, 1.2, 4},
        {104, Status::ACTUAL,  0.3, 5},
    };
    SortDocuments(documents);
    for (const Document& document : documents) {
        cout << document.id << ' '
             << static_cast<int>(document.status) << ' '
             << document.relevance << ' '
             << document.rating << endl;
    }
 
    return 0;
}
*/