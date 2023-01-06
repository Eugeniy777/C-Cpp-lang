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
    for (int i = 0; i < N; i+=2) {
        cout << arr[i] << ' ';
    }

    // var. 2 (vector)
/*
        int n;
	cin >> n;
	vector <int> arr(n);
	//считывание
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	//обработка и вывод
	for (int i = 0; i < n; i += 2) {
		cout << arr[i] << " ";
	}
*/
  return 0;
}




/*
 Выведите все элементы массива с четными индексами (то есть A[0], A[2], A[4], ...).

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу.
*/