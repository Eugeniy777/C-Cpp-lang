#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define PRICE 100

void init_array(int array[], int length, int value);

void print_array(int array[], int length);

int get_total_amount(int array[], int length);

int main()
{
    int prices[SIZE] = {0};
    int quantity[50] = {0};

    init_array(prices, SIZE, PRICE);
    init_array(quantity, 50, 10);

    puts("Prices Array");
    print_array(prices, SIZE);

    puts("Quantity Array");
    print_array(quantity, 40);

    printf("Total prices: %i\n", get_total_amount(prices, SIZE));
    printf("Total quantity: %i\n", get_total_amount(quantity, 40));

    int sum = 0;
    printf("Average: %.1f\n", (double)sum / SIZE);

    return 0;
}

/**
 * @brief Init Array
 *
 * @param int array[]
 * @param int length
 * @param int value
 */
void init_array(int array[], int length, int value)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = value;
    }
    return;
}

/**
 * @brief Print Array
 *
 * @param int array[]
 * @param int length
 */
void print_array(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Array[%i] = %i\n", i, array[i]);
    }
    return;
}

/**
 * @brief Get total amount
 * 
 * @param int array 
 * @param int length 
 * @return int 
 */
int get_total_amount(int array[], int length)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += array[i];
    }
    return total;
}