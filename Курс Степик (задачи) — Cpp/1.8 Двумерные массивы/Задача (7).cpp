#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    // sozdanie i initializatiya massiva
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    // obrabotka massiva
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(arr[i][j] == arr[j][i])) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
  return 0;
}




/*
Дано число n, не превосходящее 10, и массив размером n × n. Проверьте, является ли этот массив симметричным относительно главной диагонали. Выведите слово “YES”, если массив симметричный, и слово “NO” в противном случае.
*/