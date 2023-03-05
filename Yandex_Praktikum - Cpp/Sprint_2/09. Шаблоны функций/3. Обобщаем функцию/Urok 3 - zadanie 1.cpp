#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <typename Term>
map<Term, int> ComputeTermFreqs(const vector<Term> &terms)
{
    map<Term, int> term_freqs;
    for (const Term &term : terms)
    {
        ++term_freqs[term];
    }
    return term_freqs;
}

// верните животного с максимальной частотой
// если максимальное число раз встречаются несколько животных, выведите наименьшего из них
const pair<string, int> FindMaxFreqAnimal(const vector<pair<string, int>> &animals)
{
    // const pair<const pair<string, int>, int>
    // const auto cats = ComputeTermFreqs(animals);
    pair<string, int> best_cat;

    int max = 0;
    // sravnivaem NUMs
    for (const auto &[cat, num] : ComputeTermFreqs(animals))
    {
        if (num > max)
        {
            best_cat = cat;
            max = num;
        }

    }
    return best_cat;
}

int main()
{
    const vector<pair<string, int>> animals = {
        {"Murka"s, 5}, // 5-летняя Мурка
        {"Belka"s, 6}, // 6-летняя Белка
        {"Murka"s, 7}, // 7-летняя Мурка не та же, что 5-летняя!
        {"Murka"s, 5}, // Снова 5-летняя Мурка
        {"Belka"s, 6}, // Снова 6-летняя Белка
        
    };
    const pair<string, int> max_freq_animal = FindMaxFreqAnimal(animals);
    cout << max_freq_animal.first << " "s << max_freq_animal.second << endl;
}




/*
Задание 1


Убедимся, что полученная шаблонная функция может иметь и более сложный параметр-тип. Примените шаблонную функцию ComputeTermFreqs и определите, какое животное встречается наибольшее число раз. Животное в этом задании задаётся парой pair<string, int>, содержащей имя и возраст.
Если максимальное число раз встречаются несколько животных, выведите наименьшего из них. Гарантируется, что вектор содержит хотя бы одно животное.
Попробуйте сделать то же самое со структурой Animal вместо пары. Ничего не получится, если не научите компилятор сравнивать эти структуры. Это нормально.
*/




/*
// Решение от авторов:


#include <iostream>
#include <map>
#include <string>
#include <vector>
 
using namespace std;
 
template <typename Term>
map<Term, int> ComputeTermFreqs(const vector<Term>& terms) {
    map<Term, int> term_freqs;
    for (const Term& term : terms) {
        ++term_freqs[term];
    }
    return term_freqs;
}
 
// можно было бы обойтись без копирований и вернуть ссылку,
// но это несколько усложнит код функции — обсудим позже
pair<string, int> FindMaxFreqAnimal(const vector<pair<string, int>>& animals) {
    int max_freq = 0;
    pair<string, int> max_freq_animal;
    for (const auto& [animal, freq] : ComputeTermFreqs(animals)) {
        if (freq > max_freq) {
            max_freq = freq;
            max_freq_animal = animal;
        }
    }
    return max_freq_animal;
}
 
int main() {
    const vector<pair<string, int>> animals = {
        {"Murka"s, 5},
        {"Belka"s, 6},
        {"Murka"s, 7},
        {"Murka"s, 5}, 
        {"Belka"s, 6},
    };
    const pair<string, int> max_freq_animal = FindMaxFreqAnimal(animals);
    cout << max_freq_animal.first << " "s
         << max_freq_animal.second << endl;
    return 0;
}
*/