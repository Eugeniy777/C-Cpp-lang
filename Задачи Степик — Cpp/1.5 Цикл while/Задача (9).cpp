#include <iostream>
using namespace std;

int main() {
 int a, b = 0;
    cin >> a;
    if (a == 0) 
    {
        cout << b;
    }
    else
    {
        while (a != 0)
        {
            if (a > b)
            {
                b = a;
            }
            cin >> a;
        }
        cout << b;
    }

    // var. 2
/*
    int a = 1, b = 0;
    
    while (a) {
        cin >> a;
        if (a > b) {
            b = a;
        }
    }
    cout << b;
*/

  return 0;
}




/*
 Последовательность состоит из натуральных чисел и завершается числом 0. Определите значение наибольшего элемента последовательности.
Формат входных данных:
Вводится последовательность целых чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит, а служит как признак ее окончания).

Формат выходных данных:
Выведите ответ на задачу.
*/