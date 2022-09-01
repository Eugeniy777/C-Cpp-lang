#include <stdio.h>

#define SIZE 10

int main()
{
    int a[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        printf("a[%i]: %i\n", i, a[0]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("a[%i]: %i\n", i, a[0]);
        a[i] = i;
    }

    return 0;
}