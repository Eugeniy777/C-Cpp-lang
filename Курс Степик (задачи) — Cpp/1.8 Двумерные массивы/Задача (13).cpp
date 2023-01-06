#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m, z = 1, x = 1;
    cin >> n >> m;
    // sozdanie i initializatiya massiva
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = z;
            z++;
        }
    }
    // obrabotka massiva
    for (z = 0; z <= m + n -1; z++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == z - j) {
                    arr[i][j] = x;
                    x++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }    
  return 0;
}




/*
По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m “диагоналями”, как показано в примере.
Формат входных данных

Вводятся два числа n и m, не превышающие 100.
Формат выходных данных

Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.
*/