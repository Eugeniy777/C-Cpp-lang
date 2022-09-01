#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

// #define SIZE 10

int main()
{
    srand(time(0));

    //odnomerbyi massiv
    int size_odnom_array = 10;
    // sozdaem ukazatel i vydelyaem pamyat' pod massiv
    int *pa = (int *)malloc(size_odnom_array * sizeof(int));
    // zapolnyaem massiv
    for (int i = 0; i < size_odnom_array; i++)
    {
        //printf("Vvedite %i element massiva: ", i + 1);
        //scanf("%i", &pa[i]);
        *(pa + i) = rand() % 10; /* (pa + i); */
    }
    // vyvodim massiv
    for (int i = 0; i < size_odnom_array; i++)
    {
        printf("Adress %i = %i\n", pa + i, *(pa + i));
    }
    free(pa);

    //dvumerniy massiv
    int rows = 5;
    int cols = 7;
    int **matrix = (int**)malloc(rows*sizeof(int*));




    
    return 0;
}