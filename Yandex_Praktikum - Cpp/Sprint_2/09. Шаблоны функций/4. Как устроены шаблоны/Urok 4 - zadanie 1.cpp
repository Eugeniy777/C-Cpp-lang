#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <typename Documents, typename Term>
vector<double> ComputeTfIdfs(const Documents &documents, const Term &term)
{
    vector<double> tf_idf;
    double tf, idf;
    int tmp = 0;
    // documents - vector<vector<string>>
    for (const auto &document : documents)
    {
        // считаем document_freq (количество вхождений слова в документ)
        int document_freq = count(document.begin(), document.end(), term);
        if (document_freq > 0)
        {
            // считаем TF (доля слов документа, совпадающих с term)
            tf = (double)document_freq / (double)document.size();
            tf_idf.push_back(tf);
            ++tmp;
        }
        else
        {
            // слов в конкретном документе нет
            tf_idf.push_back(0);
        }
    }
    // считаем IDF (вычисляется для слова независимо от конкретного документа и равен логарифму
    // log(documents.size() / document_freq), 
    // где document_freq — это количество документов, содержащих term
    idf = log((double)documents.size() / (double)tmp);

    // считаем tfidf для каждого документа
    for (auto &tf : tf_idf)
    {
        tf *= idf;
    }
    return tf_idf;
}

int main()
{
    const vector<vector<string>> documents = {
        {"белый"s, "кот"s, "и"s, "модный"s, "ошейник"s},
        {"пушистый"s, "кот"s, "пушистый"s, "хвост"s},
        {"ухоженный"s, "пёс"s, "выразительные"s, "глаза"s},
    };
    const auto &tf_idfs = ComputeTfIdfs(documents, "кот"s);
    for (const double tf_idf : tf_idfs)
    {
        cout << tf_idf << " "s;
    }
    cout << endl;
    return 0;
}




/*
Задание 1


Реализуйте шаблонную функцию ComputeTfIdfs, которая вычисляет TF-IDF заданного слова для каждого документа из набора.

    Первый параметр documents — контейнер документов. циклом for (const auto& document : documents) можно перебрать все документы в нём, а в каждом документе — все слова. Тип слова, документа и набора документов может быть произвольным — ваша функция должна быть готова к любым, если есть возможность итерирования.
    Гарантируется, что и набор документов, и каждый отдельный документ имеют методы begin, end и size. Например, документом может быть строка, а словом — символ.
    Второй параметр term — слово, у которого нужно вычислить TF-IDF. Его тип совпадает с типом слов, которые получаются при итерировании по документу.
    Функция должна вернуть вектор вещественных чисел, который совпадает по длине с количеством документов. В первом элементе должен лежать TF-IDF слова term для первого документа, в последнем элементе — TF-IDF слова term для последнего документа.

Напоминаем, что TF-IDF — это произведение TF и IDF. TF слова term в документе — доля слов документа, совпадающих с term. IDF вычисляется для слова независимо от конкретного документа и равен логарифму (функция log из <cmath>) от documents.size() / document_freq, где знаменатель — это количество документов, содержащих term.
Пример из тренажёра должен вывести 0.081093 0.101366 0.
*/




/*
// Решение от авторов:


// tf_06.cpp
 
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
 
using namespace std;
 
/* MATCHER: SuccessMatcher */
 
template <typename Documents, typename Term>
vector<double> ComputeTfIdfs(const Documents& documents, const Term& term) {
    vector<double> tf_idfs;
 
    int document_freq = 0;
    for (const auto& document : documents) {
        const int freq = count(document.begin(), document.end(), term);
        if (freq > 0) {
            ++document_freq;
        }
        tf_idfs.push_back(static_cast<double>(freq) / document.size());
    }
 
    const double idf = log(static_cast<double>(documents.size()) / document_freq);
    for (double& tf_idf : tf_idfs) {
        tf_idf *= idf;
    }
 
    return tf_idfs;
}
 
int main() {
    const vector<vector<string>> documents = {
        {"белый"s, "кот"s, "и"s, "модный"s, "ошейник"s},
        {"пушистый"s, "кот"s, "пушистый"s, "хвост"s},
        {"ухоженный"s, "пёс"s, "выразительные"s, "глаза"s},
    };
    const auto& tf_idfs = ComputeTfIdfs(documents, "кот"s);
    for (const double tf_idf : tf_idfs) {
        cout << tf_idf << " "s;
    }
    cout << endl;
    return 0;
}
*/