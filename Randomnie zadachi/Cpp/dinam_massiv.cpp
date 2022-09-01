#include <iostream>
using namespace std;

int main()
{
    int size;
    printf("Enter array size: ");
    scanf_s("%d", &size);
    getchar();
    int *pa = new int[size];
    for (int i = 0; i < size; i++)
    {
        pa[i] = rand() % 10;
        cout << (pa + i) << ' ' << *(pa + i) << endl;
    }
    delete[] pa;
    pa = nullptr;
    // system("cls");
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}