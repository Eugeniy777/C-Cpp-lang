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
        if ((arr[i] > 0 && arr[i-1] > 0) || (arr[i] < 0 && arr[i-1] < 0)) {
            if (arr[i] < arr [i-1]) {
                cout << arr[i] << ' ' << arr[i-1] << ' ';
            }
            else 
                cout << arr[i - 1] << ' ' << arr[i] << ' ';
            break;
        }
    }

    // var. 2 (vector)
/*
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i - 1] * a[i] > 0) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
            }
            cout << a[i - 1] << " " << a[i];
            break;
        }
    }
*/

  return 0;
}




/*
 Дан массив целых чисел. Если в нем есть два соседних элемента одного знака, выведите эти числа. Если соседних элементов одного знака нет - не выводите ничего. Если таких пар соседей несколько - выведите первую пару.

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива. Все числа отличны от нуля. 

Формат выходных данных:
Выведите ответ на задачу. Элементы выводятся в порядке неубывания.
*/