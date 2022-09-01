#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int size = 0;
    cout << "Enter array size: " << endl;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t" << arr + i << endl;
        // printf("Array[%i] = %i. Adress: %i\n", i+1, arr[i], arr + i);
    }
    delete[] arr;
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}

