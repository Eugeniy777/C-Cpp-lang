#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
// sozdanie, zapolnenie i obrabotka
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = j - i;
        }
    }
// vyvod
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << abs(arr[i][j]) << ' ';
        }
        cout << endl;
    }
  return 0;
}




/*
Дано число n, не превышающее 100. Создайте массив размером n×n и заполните его по следующему правилу. На главной диагонали должны быть записаны числа 0. На двух диагоналях, прилегающих к главной, числа 1. На следующих двух диагоналях числа 2, и т.д. Выведите полученный массив на экран, разделяя элементы массива пробелами.
*/