#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    // sozdanie i initializatiya massiva
    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    // swap stolbcov i & j
    int i, j;
    cin >> i >> j;
    for (int n = 0; n < rows; n++) {
        for (int m = 0; m < cols; m++) {
            if(i == m) {
                swap(arr[n][i], arr[n][j]);
            //arr[n][i] = arr[n][i] + arr[n][j];
            //arr[n][j] = arr[n][i] - arr[n][j];
            //arr[n][i] = arr[n][i] - arr[n][j];
            }
        }
    }
    // vyvod 
    for (int n = 0; n < rows; n++) {
        for (int m = 0; m < cols; m++) {
            cout << arr[n][m] << ' ';
        }
        cout << endl;
    }
  return 0;
}




/*

Дан двумерный массив и два числа: i и j. Поменяйте в массиве столбцы с номерами i и j
Формат входных данных:
Программа получает на вход размеры массива n и m, не превосходящие 100, затем элементы массива, затем числа i и j.

Формат выходных данных:
Выведите результат.
*/