#include <iostream>
using namespace std;
int main() {
  int a, fib;
    int f=0, g=1, i=0;
    cin >> a;
    while (f < a)
    {
    fib = f + g;
    f = g;
        g = fib;
        i++;
    }
    if (a==f)cout << i;
    else cout << "-1";

    // ver. 2
/*
    int x, i = 2, now = 1, prev = 1, prev2 = 1;
    cin >> x;
    while (x >= now) {
        if (x==now) {
            cout << i;
            return 0;
        }
            now = prev + prev2;
            prev2 = prev;
            prev = now;
            i++;
        }
        cout << -1;
*/

  return 0;
}




/*
Последовательность Фибоначчи определяется так: 

F(0) = 0, F(1) = 1, …, F(n) = F(n−1) + F(n−2).

Дано натуральное число A. Определите, каким по счету числом Фибоначчи оно является, то есть выведите такое число N, что F(N) = A. Если А не является числом Фибоначчи, выведите число -1.
Формат входных данных:
Вводится натуральное число A > 1.

Формат выходных данных:
Выведите ответ на задачу.
*/