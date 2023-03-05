#include <iostream>
#include <set>
#include <string>
#include <numeric>

using namespace std;

string sum(const string &a, const string &b)
{
    return a + " -"s + b;
}

string AddStopWords(const string &query, const set<string> &stop_words)
{
    string stroka = accumulate(stop_words.begin(), stop_words.end(), query, sum);
    return stroka;
}




/*
Задание 1


Алгоритм accumulate может работать не только с вектором, но и с другими контейнерами — например, с set. Напишите функцию AddStopWords, которая принимает строку-запрос и множество стоп-слов и возвращает новую строку. В новой строке после запроса идут стоп-слова через пробел, перед каждым стоит дефис. Передайте в accumulate четвёртым аргументом функцию, сворачивающую множество стоп-слов в «хвост» нужного формата.
Пример
Запрос				Стоп-слова		Выходная строка
"some tasty oranges"		{"of", "in"}		"some tasty oranges -in -of"
Так как порядок ввода стоп-слов неважен, и вы используете контейнер set, порядок стоп-слов в выходной строке будет алфавитным, вне зависимости от того, в каком порядке стоп-слова оказались в этом контейнере.
*/




/*
// Решение от авторов:


#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <numeric>
 
using namespace std;
 
string FoldWithMinus(string left, string right) {
    return left + " -"s + right;
}
 
string AddStopWords(const string& query, const set<string>& stop_words) {
    return query + std::accumulate(stop_words.begin(), stop_words.end(), ""s, FoldWithMinus);
}


// Можно было бы сделать изящней и задать query вместо ""s в качестве начального значения аккумулятора:
return std::accumulate(stop_words.begin(), stop_words.end(), query, FoldWithMinus);
*/