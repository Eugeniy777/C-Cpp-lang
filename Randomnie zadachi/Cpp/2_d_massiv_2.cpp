#include <iostream>
using namespace std;

int main()
{
    int rows = 0;
    int cols = 0;
    printf("Vvedite kol-vo strok: ");
    cin >> rows;
    printf("Vvedite kol-vo kolonok: ");
    cin >> cols;
    int **pa = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        pa[i] = new int[cols];
    }
    // zapolnenie massiva
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            pa[i][j] = rand() % 77;
            cout << *(*(pa + i) + j) << ' ';
            // printf("%2d %2d ", pa[i][j], *(*(pa + i) + j));
        }
        cout << endl;
    }
    // udalenie kolonok
    for (int i = 0; i < rows; i++)
    {
        delete[] pa;
    }
    // udalenie ukazatelya
    delete[] pa;
    //g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}