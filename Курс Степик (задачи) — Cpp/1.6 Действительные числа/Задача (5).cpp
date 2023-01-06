#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, p, s;
    cin >> a >> b >> c;
    p = (a + b + c) / 2.;
    s = p*(p-a)*(p-b)*(p-c);
    cout << sqrt(s);
  return 0;
}




/*
 Даны длины сторон треугольника. Вычислите площадь треугольника.
Формат входных данных:
Вводятся три положительных числа.

Формат выходных данных:
Выведите ответ на задачу.
*/