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
    //nahodim perviy nechetniy element massiva
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 != 0) {
           min = arr[i];
            break;
        }
    }
    //nahodim minimalniy nechetniy element massiva
    for (int i = 0; i < N; i++) {
        if (arr[i] < min && arr[i] % 2 != 0) {
           min = arr[i];
        }
    }
    cout << min;

    // var. 2 (vector)
/*
    int n, min = 0;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 != 0) {
            if (min == 0 || min > a[i]) { 
                min = a[i]; 
            }
        }
    }
    cout << min;
*/

  return 0;
}




/*
Выведите значение наименьшего нечетного элемента списка, а если в списке нет нечетных элементов - выведите число 0.

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу.
*/