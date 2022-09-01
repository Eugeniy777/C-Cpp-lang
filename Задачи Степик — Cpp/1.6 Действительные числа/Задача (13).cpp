#include <iostream>

using namespace std;
int main() {
    double a, b, c, d, e, f, D, Dx, Dy ;
    cin >> a >> b >> c >> d >> e >> f;
    D = a * d - b * c;
    Dx = e * d - b * f;
    Dy = a * f - e * c;
    cout << Dx / D << " " << Dy / D << endl;
    return 0;
}




/*


Даны вещественные числа a, b, c, d, e, f. Известно, что система линейных уравнений
ax + by = e,
{
cx + dy = f.
имеет ровно одно решение. Выведите два числа x и y, являющиеся решением этой системы.

Формат входных данных:
Вводятся шесть чисел - коэффициенты уравнений системы.

Формат выходных данных:
Выведите ответ на задачу.
*/