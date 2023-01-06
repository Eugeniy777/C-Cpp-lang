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
    //nahodim minimalniy element massiva
    for (int i = 0; i < N; i++) {
        if (arr[i] < min && arr[i] % 2 != 0) {
           min = arr[i];
        }
    }
    cout << min;

    // ver. 2 (vector)
/*
    int count = 0;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i + 1]) {
            count++;
        }
    }
    cout << count;
*/

  return 0;
}




/*
 Дан список, упорядоченный по неубыванию элементов в нем. Определите, сколько в нем различных элементов.

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу.
*/