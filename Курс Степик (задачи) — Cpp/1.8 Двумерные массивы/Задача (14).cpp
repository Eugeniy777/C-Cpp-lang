#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m, z = 1;
    cin >> n >> m;
    // sozdanie i initializatiya massiva
    int arr[n][m]{};
    // obrabotka massiva
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            for (int j = 1; j < m; j+=2) {
                arr[i][j] = z;
                z++;
            }
        }
        else {
            for (int j = 0; j < m; j+=2) {
                arr[i][j] = z;
                z++;
            }
        }
    }
    // vyvod massiva
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
  return 0;
}




/*
Даны числа n и m. Заполните массив размером n × m в шахматном порядке: клетки одного цвета заполнены нулями, а другого цвета - заполнены числами натурального ряда сверху вниз, слева направо. В левом верхнем углу записано число 1.
Формат входных данных

Вводятся два числа n и m, не превышающие 100.
Формат выходных данных

Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.
*/