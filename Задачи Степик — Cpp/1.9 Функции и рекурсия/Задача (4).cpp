#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
T distance1 (T x1, T y1, T x2, T y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << distance1(a, b, c, d);
    
  return 0;
}




/*
Даны четыре действительных числа: x1, y1, x2, y2. Напишите функцию distance(x1, y1, x2, y2), вычисляющую расстояние между точкой (x1, y1) и (x2, y2). Считайте четыре действительных числа и выведите результат работы этой функции.
Формат входных данных
Вводятся четыре действительных числа.
Формат выходных данных
Выведите ответ на задачу.
*/