#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nN, z = 0;
    cin >> nN;
    const int N = nN;
    int arr[N]{};
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr [i] = temp;
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            z++;
        }
    }
        cout << z << ' ';

    // var. 2 (vector)
/*
    int n, k = 0;
    cin >> n;
    vector <int> a(n);
	//считывание
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	//обработка и вывод
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) k++;
    }
    cout << k;
*/
  return 0;
}




/*
 Найдите количество положительных элементов в данном массиве.

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу.
*/