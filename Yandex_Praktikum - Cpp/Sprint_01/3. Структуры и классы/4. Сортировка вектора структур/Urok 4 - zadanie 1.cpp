#include <algorithm>
#include <vector>
using namespace std;

struct Document {
    int id;
    int relevance;
};

bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
    return lhs.relevance > rhs.relevance;
}

int main() {
    vector<Document> documents;
    sort(documents.begin(), documents.end(), HasDocumentGreaterRelevance);
}




/*
Задание 1


В коде поисковой системы документы должны быть отсортированы по убыванию релевантности. Напишите функцию-компаратор, которую нужно передать в такую сортировку.
Функция должна называться HasDocumentGreaterRelevance.

Как будет тестироваться ваш код:
Тренажёр проверит, что функция HasDocumentGreaterRelevance возвращает истинное значение тогда и только тогда, когда первый переданный ей документ имеет релевантность выше, чем второй.
*/




/*
Решение от авторов:



*/