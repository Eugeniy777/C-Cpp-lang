#include <iostream>
using namespace std;

int main() {
    int m, n, a = 0, b = 0, z = 0;
    cin >> m >> n;
    // sozdanie i initializaciya massiva
    int arr[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    // obrabotka massiva
    z = arr[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > z) {
                z = arr[i][j];
                a = i;
                b = j;
            }
        }
    }
    cout << a << ' ' << b;
  return 0;
}




/*
Найдите индексы первого вхождения максимального элемента.
Формат входных данных

Программа получает на вход размеры массива n и m, затем n строк по m чисел в каждой. n и m не превышают 100.
Формат выходных данных

Выведите два числа: номер строки и номер столбца, в которых стоит наибольший элемент в двумерном массиве. Если таких элементов несколько, то выводится тот, у которого меньше номер строки, а если номера строк равны то тот, у которого меньше номер столбца.
*/