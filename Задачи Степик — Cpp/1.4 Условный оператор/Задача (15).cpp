#include <iostream>
using namespace std;

int main() {
int a, b, c;
    cin >> a >> b >> c;
    if (a>=b && a>=c)
    {
        if (b>=c)
        {
            cout << c << ' ' << b << ' ' << a;
        }
        else
        {
            cout << b << ' ' << c << ' ' << a;
        }
    }
    else if (b>=a && b >=c)
    {
        if (c>=a)
        {
            cout << a << ' ' << c << ' ' << b;
        }
        else
        {
            cout << c << ' ' << a << ' ' << b;
        }
    }
        else if (c>=a && c>=b)
        {
            if (a>=b)
            {
                cout << b << ' ' << a << ' ' << c;
            }
            else 
            {
                cout << a << ' ' << b << ' ' << c;
            }
        }
  return 0;
}






/*
 Дано три числа. Упорядочите их в порядке неубывания.
Формат входных данных:
Вводятся три числа.

Формат выходных данных:
Выведите ответ на задачу.
*/