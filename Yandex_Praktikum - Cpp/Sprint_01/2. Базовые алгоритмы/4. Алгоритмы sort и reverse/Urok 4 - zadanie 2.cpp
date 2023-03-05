#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<bool, double> CalcMedian(vector<double> samples)
{
    sort(samples.begin(),samples.end());
    pair<bool, double> med;
    if (samples.empty())
    {
        return {false, 0};
    }
    else
    {
        if (samples.size() % 2 == 0)
        {
            double mediana = (samples[samples.size() / 2 - 1] + samples[samples.size() / 2]) / 2;
            return {true, mediana};
        }
        else
        {
            double mediana = samples[samples.size() / 2];
            return {true, mediana};
        }
    }
}

int main()
{
    int size;
    cin >> size;

    vector<double> samples;
    for (int i = 0; i < size; ++i)
    {
        double sample;
        cin >> sample;
        samples.push_back(sample);
    }

    pair<bool, double> result = CalcMedian(samples);
    if (result.first)
    {
        cout << result.second << endl;
    }
    else
    {
        cout << "Empty vector"s << endl;
    }
}




/*
Задание 2

Время ответа сервера зависит от запроса. Поэтому нужна метрика, которая позволяет адекватно оценить время работы в типичном случае.
Первая идея — смотреть на среднее время. Но это может приводить к неадекватным ответам. Например, 10% запросов не выполняются, так как время истекает, а таймаут выставлен на две секунды. Если поднять таймаут до трёх секунд, среднее время увеличится, хотя по сути ничего не изменилось.
Больше подойдёт медиана и её аналоги — процентили. Например 99-й процентиль — это значение минимального элемента, который больше 99% всех элементов массива. Чтобы не сортировать весь массив, в реальной жизни такие статистики считают алгоритмом nth_element. В задании примените медиану. Для отсортированного массива это значение среднего элемента, либо полусумма двух средних элементов, если число элементов чётное:

CalcMedian({1, 2, 3, 4}) == 2.5;
CalcMedian({1, 2, 3}) == 2;
CalcMedian({1, 2, 1000}) == 2; // медиана устойчива к небольшому числу сильно отклоняющихся от нормы значений 

Напишите функцию, которая принимает на вход вектор времени ответа и вычисляет медиану этого вектора. Вектор может быть неотсортированным.
Чтобы проверить число на чётность, используйте оператор остатка от деления:

if (x % 2 == 0) {
    // чётное
} else {
    // нечётное
} 

*/




/*
// Решение от авторов:


#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
pair<bool, double> CalcMedian(vector<double> samples) {
    if (samples.empty()) {
        return {false, 0.0};
    }
    sort(samples.begin(), samples.end());
    int index = samples.size() / 2;
    if (samples.size() % 2 == 0) {
        return {true, (samples[index - 1] + samples[index]) / 2};
    }
 
    return {true, samples[index]};
}
 
int main() {
    int size;
    cin >> size;
 
    vector<double> samples;
    for (int i = 0; i < size; ++i) {
        double sample;
        cin >> sample;
        samples.push_back(sample);
    }
 
    const auto [median_exists, median_value] = CalcMedian(samples);
    if (median_exists) {
        cout << median_value << endl;
    } else {
        cout << "Empty vector"s << endl;
    }
}
*/