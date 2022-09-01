#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, z = 1;
    cin >> N;
    //sodaem massiv
    int arr[N]{};
    //vvodim elementi massiva
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    //swap'aem 1 i 2 elementy massiva
    int i = 0;
        while (i < N - 1) {
        swap(arr[i], arr[i+1]);
        cout << arr[i] << ' ' << arr[i+1] << ' ';
            i+=2;
        }
    if (N % 2) {
    cout << arr[N-1];
    }

    // var. 2 (vector)
/*
    int n, temp;
    cin >> n;
    vector <int> a(n);
        //считывание
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
        //обработка
    for (int i = 1; i < n; i += 2) {
        temp = a[i];
        a[i] = a[i-1];
        a[i-1] = temp;
    }
        //вывод
    for (auto now : a) {
        cout << now << " ";
    }
*/

  return 0;
}




/*
 Переставьте соседние элементы массива (A[0] c A[1], A[2] c A[3] и т.д.). Если элементов нечетное число, то последний элемент остается на своем месте.

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу.
*/