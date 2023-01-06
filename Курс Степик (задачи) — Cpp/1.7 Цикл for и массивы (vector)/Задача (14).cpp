#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, z;
    cin >> N;
    // sozdanie i initializatiya massiva
    int arr[N]{};
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    // obnulyaem vse povtoryayuschiesya elementy massiva
    for (int i = 0; i < N; i++) {
        z = arr[i];
        for (int j = i+1; j < N; j++) {
            if (z == arr[j]) {
                arr[i] = 0;
                arr[j] = 0;
            }
        }
    }
    // vyvodim vse nenulevie elementy
    for (int i = 0; i < N; i++) {
        if (arr[i] != 0) {
            cout << arr[i] << ' ';
        }
    }

    // var. 2 (vector)
/*
    int n, c = 0;
    cin>>n;
    vector <int> a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0;i < n;i++){
        for(int k = 0;k < n ;k++){
            if(a[i] == a[k] && k != i){
                c++;
            }
        }
        if(c == 0){
            cout<<a[i]<<" ";
        }
        c = 0;
    }
*/

  return 0;
}




/*
 Дан массив. Выведите те его элементы, которые встречаются в массиве только один раз. Элементы нужно выводить в том порядке, в котором они встречаются в списке.

Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных
Выведите ответ на задачу.
*/