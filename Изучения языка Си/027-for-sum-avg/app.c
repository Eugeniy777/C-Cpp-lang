#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define PRICE 100

int main()
{
    int prices[SIZE] = {0};

    for (int i = 0; i < SIZE; i++)
    {
        prices[i] = rand() % 100;
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("price %i = %i\n", i + 1, prices[i]);
    }

    int total = 0;

    for (int i = 0; i < SIZE; i++)
    {
        total += prices[i];
    }
    printf("Summ: %i\n", total);
    printf("Average: %f\n", (double)total / SIZE);

    return 0;
}