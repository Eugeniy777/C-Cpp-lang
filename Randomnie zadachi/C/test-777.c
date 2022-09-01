#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main()
{
    srand(time(0));
    int size_arr = 5;
    int *ptr = (int *)malloc(size_arr * sizeof(int));
    for (int i = 0; i < size_arr; i++)
    {
        *(ptr + i) = rand() % 10;
        printf("ptr[%i] = %i", i+1, *ptr);
    }
    free(ptr);
    return 0;
}