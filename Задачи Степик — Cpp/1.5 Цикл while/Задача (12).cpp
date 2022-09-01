#include <iostream>
using namespace std;

int main() {
    int n, f = 1, i = 1, a = 2;
    cin >> n;
    if (n == 1) 
    {
        f = 1;
    }
    if (n == 2) 
    {
        f = 1;
    }
    if (n > 2) 
    {
        while (n != a) 
        {
            f = f + i;
            i = f - i;
            a = a + 1;
        }
    }
    cout << f;

    // ver. 2
/*
    int x, i = 2, now = 1, prev = 1, prev2 = 1;
    cin >> x;
    if (x == 0) {
        cout << now;
    }
    else if (x == 1) {
        cout << now;
    }
    else if (x == 2) {
        cout << now;
    }
    else if (x > 2) {
        while (i < x) {
            now = prev + prev2;
            prev2 = prev;
            prev = now;
            i++;
        }
        cout << now;
    }
*/

    return 0;
}




/*


Последовательность Фибоначчи определяется так:

F(0) = 0, F(1) = 1, …, F(n) = F(n−1) + F(n−2).

По данному числу N определите N-е число Фибоначчи F(N).
Формат входных данных:
Вводится натуральное число N.

Формат выходных данных:
Выведите ответ на задачу.
*/