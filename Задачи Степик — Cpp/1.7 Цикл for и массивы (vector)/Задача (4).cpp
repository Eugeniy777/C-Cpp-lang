#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nN;
    cin >> nN;
    const int N = nN;
    int arr[N]{};
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr [i] = temp;
    }
    for (int i = 0; i < N; i++) {
        if (!(arr[i]%2)) {
            cout << arr[i] << ' ';
        }
    }

    // var. 2 (vector)
/*
    int n;
    cin >> n;
    vector <int> a(n);
	//считывание
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	//обработка и вывод
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cout << a[i] << " ";
        }
    }
*/
  return 0;
}




/*
 Выведите все четные элементы массива.

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу. Элементы выводятся в том же порядке, в котором они стояли в массиве.
*/