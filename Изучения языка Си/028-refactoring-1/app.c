#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define PRICE 100

// peredacha massiva v funkciyu 
void init_array(int array[], int length, int value)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = value;
    }
    return;
}

int main()
{
    int prices[SIZE] = {0};
    int quantity[50] = {0};

    init_array(prices, SIZE, PRICE);
    init_array(quantity, 50, 10);

    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        printf("price %i = %i\n", i + 1, prices[i]);
        sum += prices[i];
    }

    printf("Summ: %i\n", sum);
    printf("Average: %.1f\n", (double)sum / SIZE);

    return 0;
}