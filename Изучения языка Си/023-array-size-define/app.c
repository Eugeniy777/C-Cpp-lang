#include <stdio.h>

#define SIZE 5

int main()
{
    int prices[SIZE] = {100, 200, 300, 400, 500};

    printf("First element: %i\n", prices[SIZE - SIZE]);
    printf("Prev element: %i\n", prices[SIZE - 2]);
    printf("Last element: %i\n", prices[SIZE - 1]);
    printf("Last element: %i\n", prices[SIZE]); // musor
    

    return 0;
}