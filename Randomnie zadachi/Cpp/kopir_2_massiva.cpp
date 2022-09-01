#include <iostream>
using namespace std;

void fill_array(int* const, const int);
void show_array(const int *const, const int);

int main()
{
    int size = 10;
    int *first_array = new int[size];
    int *second_array = new int[size];

    fill_array(first_array, size);
    fill_array(second_array, size);
    cout << "First array: " << endl;
    show_array(first_array, size);
    cout << "Second array: " << endl;
    show_array(second_array, size);
    cout << "====================================" << endl;
    //snachala udalyaem 1st massiv
    delete[] first_array;
    //sozdaem mesto razmerom 2nd massiv
    first_array = new int[size];
    // prisvaivaem znacheniya vtorogo massiva v perviy
    for (int i = 0; i < size; i++)
    {
        first_array[i] = second_array[i];
    }
    cout << "====================================" << endl;
    cout << "First array: " << endl;
    show_array(first_array, size);
    cout << "Second array: " << endl;
    show_array(second_array, size);
    cout << "====================================" << endl;
    delete[] first_array;
    delete[] second_array;
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
} 

void fill_array(int* const array, const int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

void show_array(const int *const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}