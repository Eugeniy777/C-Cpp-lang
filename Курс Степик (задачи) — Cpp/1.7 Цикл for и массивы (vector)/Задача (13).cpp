#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, z = 0;
    cin >> N;
    // sozdanie i initializatiya massiva
    int arr[N]{};
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] == arr[j]) {
                z++;
            }
        }
    }
    cout << z;

    // var. 2 (vector)
/*
    int n;
    cin >> n;

    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                counter = counter + 1;
            }
        }
    }
    cout << counter << endl;
*/

  return 0;
}




/*
 Дан массив чисел. Посчитайте, сколько в нем пар элементов, равных друг другу. Считается, что любые два элемента, равные друг другу образуют одну пару, которую необходимо посчитать.

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных:
Выведите ответ на задачу.
*/