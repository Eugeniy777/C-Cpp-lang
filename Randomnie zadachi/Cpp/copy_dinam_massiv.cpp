#include <iostream>
using namespace std;

void fill_array(int[], const int, const char[]);
void show_array(const int[], const int, const char[]);

int main()
{
    int size = 10;
    int *first_array = new int[size];
    int *second_array = new int[size];

    fill_array(first_array, size, "first_array = ");
    fill_array(second_array, size, "second_array = ");

    show_array(first_array, size, "first_array = ");
    show_array(second_array, size, "second_array = ");

    delete[] first_array;
    int new_size = 10;
    first_array = new int[new_size];
    for (int i = 0; i < new_size; i++)
    {
        first_array[i] = second_array[i];
    }
    
    show_array(first_array, size, "first_array = ");
    show_array(second_array, size, "second_array = ");

    delete[] first_array;
    delete[] second_array;
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}

void fill_array(int array[], const int size, const char name[])
{
    printf("%s\n", name);
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

void show_array(const int array[], const int size, const char name[])
{
    printf("%s\n", name);
    for (int i = 0; i < size; i++)
    {
        printf("%d = %d\n", array + i, *(array + i));
    }
}