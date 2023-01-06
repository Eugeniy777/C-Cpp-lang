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
        arr[i] = temp;
    }
    for (int i = 0; i < N; i++) {
        if (i != 0 && arr[i] > arr[i-1]) {
        cout << arr[i] << ' ';
        }
    }

    // var. 2 (vector)
/*
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    for (int i = 1; i < n; i++)	{
        cin >> a[i];
        if (a[i] > a[i - 1]) {
        cout << a[i] << " ";
        }
    }
*/

  return 0;
}




/*
 Дан массив чисел. Выведите все элементы массива, которые больше предыдущего элемента .

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу.
*/