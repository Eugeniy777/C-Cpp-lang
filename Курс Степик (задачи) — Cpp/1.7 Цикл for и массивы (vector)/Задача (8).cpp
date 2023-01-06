#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, min = 0;
    cin >> N;
    //sodaem massiv
    int arr[N]{};
    //vvodim elementi massiva
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    //nahodim perviy polozhitelniy element massiva
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
           min = arr[i];
            break;
        }
    }
    //nahodim minimalniy polozhitelniy element
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0 && arr[i] < min) {
           min = arr[i];
        }
    }
    cout << min;

    // var. 2 (vector)
/*
    int n, t, o = 100500;
    vector <int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    };
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] < o) o = a[i]; 
    };
    cout << o;
*/

  return 0;
}




/*
 Выведите значение наименьшего из всех положительных элементов в массиве. Известно, что в массиве есть хотя бы один положительный элемент.

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу.
*/