#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 16;
    int arr[N]{};
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    for (int i = 0; i < N-2; i += 2) {
        for (int j = i+2; j < N-2; j += 2 ) {
            if (arr[i] == arr[j] || arr[i+1] == arr[j+1] || abs(arr[i] - arr[j]) == abs(arr[i + 1] - arr[j+1])) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    // var. 2 (vector)
/*
    vector <int> h(8); // вектор горизонталей ферзей
    vector <int> v(8); // вектор вертикалей ферзей
	// заполнение векторов
    for (int i = 0;i < 8;i++) 
        cin >> h[i]>>v[i];
        // обработка и вывод
    for (int i = 0;i < 8;i++) {
        int tempH = h[i];
        int tempV = v[i];
            for (int j = 0;j < 8;j++) {
                if (i != j && (tempH == h[j] || tempV == v[j])) {
                    cout << "YES";
                    return 0;
                }
                if (i != j && (abs(tempH - h[j]) == abs(tempV - v[j]))) {
                    cout << "YES";
                    return 0;
                }
            }
    }
	// Вывод результата
	cout << "NO";
*/

  return 0;
}




/*
 Известно, что на доске 8×8 можно расставить 8 ферзей так, чтобы они не били друг друга. Вам дана расстановка 8 ферзей на доске, определите, есть ли среди них пара бьющих друг друга.

Формат входных данных
Программа получает на вход восемь пар чисел, каждое число от 1 до 8 - координаты 8 ферзей.
Формат выходных данных
Если ферзи не бьют друг друга, выведите слово NO, иначе выведите YES.
*/