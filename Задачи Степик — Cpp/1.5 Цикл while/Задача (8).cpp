#include <iostream>
using namespace std;

int main() {
int a, sum;
    cin >> a;
    sum = 0;
    while (a!=0)
    { 
        sum = sum + a;
        cin >> a;
    }
    cout << sum;

  return 0;
}






/*
 Определите сумму всех элементов последовательности, завершающейся числом 0.
Формат входных данных:
Вводится последовательность целых чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит, а служит как признак ее окончания.

Формат выходных данных:
Выведите ответ на задачу.
*/