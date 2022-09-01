#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, temp;
    cin >> N;
    // sozdanie i zapolnenie massiva
    int arr[N]{};
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr[i] = temp;
    }
    // peremeschaem elementi
    temp = arr[N-1];
    for (int i = (N - 1); i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    //  vyvodim massiv
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    // var. 2 (vector)
/*
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    cout<<a[n-1]<<" ";
    for(int i = 0;i < n-1;i++){
        cout<<a[i]<<" ";
}
*/

  return 0;
}




/*
 Циклически сдвиньте элементы списка вправо (A[0] переходит на место A[1], A[1] на место A[2], ..., последний элемент переходит на место A[0]).

Формат входных данных:
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных:
Выведите ответ на задачу.
*/