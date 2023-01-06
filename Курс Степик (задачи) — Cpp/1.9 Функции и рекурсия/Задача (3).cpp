#include <iostream>
using namespace std;

// нельзя использовать в шаблоне название min, т.к. из-за "using namespace std" происходит конфликт имён
template <typename T>
T min1 (T a, T b) {
    return (a < b) ? a : b;
}
template <typename T1>
T1 min4 (T1 a, T1 b, T1 c, T1 d) {
return min1(min1(a, b), min1(c, d));
//T1 e = min1(a, b);
//T1 f = min1(c, d);
    //return (e < f) ? e : f;
    }

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min4(a, b, c, d);
  return 0;
}




/*
Напишите функцию min(a, b), вычисляющую минимум двух чисел. Затем напишите функцию min4(a, b, c, d), вычисляющую минимум 4 чисел с помощью функции min. Считайте четыре целых числа и выведите их минимум.
Формат входных данных:
Вводятся четыре целых числа.
Формат выходных данных:
Выведите ответ на задачу.
*/