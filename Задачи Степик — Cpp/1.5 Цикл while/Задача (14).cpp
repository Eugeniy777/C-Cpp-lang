#include <iostream>
using namespace std;

int main() {
    int i = 0, vh = 1, temp = 1, max = 1;
        while (vh) {
            cin >> vh;
            if (!vh) {
                break;
            }
            if (vh==temp) {
                i++;
                if (i > max) {
                max = i;
                }
                continue;
            }
            else if (vh != temp) {
                i = 1;
            }
            temp = vh;
        }
            cout << max;
  return 0;
}




/*
 Дана последовательность натуральных чисел, завершающаяся числом 0. Определите, какое наибольшее число подряд идущих элементов этой последовательности равны друг другу. Если не нашлось ни одной пары, тройки и т.д. элементов, равных друг другу, то программа должна вывести число 1.
Формат входных данных:
Вводится последовательность натуральных чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит, а служит как признак ее окончания).

Формат выходных данных:
Выведите ответ на задачу.
