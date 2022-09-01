#include <iostream>
using namespace std;

double pow(double a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return pow(a * a, n / 2);
    else return a * pow(a, n - 1);
}

int main() {
    double a;
    int n;
    cin >> a >> n;
    cout << pow(a, n);
    return 0;
}




/*
Возводить в степень можно гораздо быстрее, чем за n умножений! Для этого нужно воспользоваться следующими рекуррентными соотношениями:

a^n = (a^2)n/2  при четном n,

a^n = a × a^n−1 при нечетном n.

Реализуйте алгоритм быстрого возведения в степень с помощью рекурсивной функции.
Формат входных данных:
Вводятся действительное число a и целое неотрицательное число n.

Формат выходных данных:
Выведите ответ на задачу.
*/