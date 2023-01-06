#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // sozdanie i initializaciya massiva
    int arr[n][m], a[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            // zapolnenie vtoroogo massiva
            a[j][i] = arr[i][j];
        }
    }
    // vyvod vtorogo massiva
    for (int i = 0; i < m; i++) {
        for (int j = n-1; j >= 0; j--) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
  return 0;
}




/*
Дан прямоугольный массив размером n×m. Поверните его на 90 градусов по часовой стрелке, записав результат в новый массив размером m×n.
Формат входных данных
Вводятся два числа n и m, не превосходящие 100, затем массив размером n×m.
Формат выходных данных

Выведите получившийся массив. Числа при выводе разделяйте одним пробелом.
*/