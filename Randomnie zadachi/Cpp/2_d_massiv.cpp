#include <iostream>
using namespace std;

int main()
{
    int rows = 3;
    int cols = 5;
    cout << "Vvedite kol-vo strok: " << endl;
    cin >> rows;
    cout << "Vvedite kol-vo kolonok: " << endl;
    cin >> cols;
    // sozdanie odnomernogo massiva ukazateley
    int **arr = new int *[rows];
    // zapolnenie massiva ukazateley kolonkami
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    // zapolnenie massiva
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    // vyvod massiva
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    // udalyaem stroki
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    // udalyaem kolonku ukazateley
    delete[] arr;
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}