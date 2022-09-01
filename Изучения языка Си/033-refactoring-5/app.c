#include <stdio.h>
#include <stdlib.h>

#define SIZE_PRICES 10
#define SIZE_QUANTITIES 50
#define PRICE 100
#define QUANTITY 10

/**
 * INTERFACE
 */
void init_array(int[], const int, const int);
void print_array(const int[], const int, const char[]);
int get_total_amount(const int[], const int);
double get_average_value(const int, const int);

int main()
{
    int prices[SIZE_PRICES] = {0};
    int quantities[SIZE_QUANTITIES] = {0};

    init_array(prices, SIZE_PRICES, PRICE);
    init_array(quantities, SIZE_QUANTITIES, QUANTITY);

    // puts("Prices Array");
    print_array(prices, SIZE_PRICES, "prices");

    // puts("quantities Array");
    print_array(quantities, SIZE_QUANTITIES, "quantities");

    int prices_total_amount = get_total_amount(prices, SIZE_PRICES);
    int quantities_total_amount = get_total_amount(quantities, SIZE_QUANTITIES);

    printf("Total prices: %i\n", prices_total_amount);
    printf("Total quantities: %i\n", quantities_total_amount);
    printf("Prices average value: %.1lf\n", get_average_value(prices_total_amount, SIZE_PRICES));
    printf("quantities average value: %.1lf\n", get_average_value(quantities_total_amount, SIZE_QUANTITIES));

    return 0;
}

/**
 * @brief Init Array
 *
 * @param int array[]
 * @param int length
 * @param int value
 */
void init_array(int array[], const int length, const int value)
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
 * @param char name[]
 */
void print_array(const int array[], const int length, const char name[])
{
    for (int i = 0; i < length; i++)
    {
        printf("%s: [%i] = %i\n", name, i, array[i]);
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
int get_total_amount(const int array[], const int length)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += array[i];
    }
    return total;
}

/**
 * @brief Get average value
 * 
 * @param total_amount 
 * @param length 
 * @return double 
 */
double get_average_value(const int total_amount, const int length)
{
    return (double)total_amount / length;
}