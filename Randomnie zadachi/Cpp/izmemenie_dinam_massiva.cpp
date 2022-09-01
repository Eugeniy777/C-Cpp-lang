#include <iostream>
using namespace std;

void fill_array(int[], const int, const char[]);
void show_array(const int[], const int, const char[]);

void push_back(int *&array, int &size, const int new_value);
void pop_back(int *&array, int &size);

int main()
{
    int size = 5;
    int *arr = new int[size];

    fill_array(arr, size, "hello");
    show_array(arr, size, "hello");

    push_back(arr, size, 788);
    show_array(arr, size, "hello");

    pop_back(arr, size);
    show_array(arr, size, "hello");

    delete[] arr;
    //g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
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

void push_back(int *&array, int &size, const int new_value)
{
    int *new_array = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        new_array[i] = array[i];
    }
    new_array[size] = new_value;
    size++;

    delete[] array;
    array = new_array;
}

void pop_back(int *&array, int &size)
{
    size--;
    int *new_array = new int[size];
    for (int i = 0; i < size; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
}

