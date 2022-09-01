#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void init_massiv(int[], const int);
void vyvod_massiva(int[], const int);
void ptr_func(int*, int*, int*);

int main()
{
    srand(time(0));
    /*
    int a = 5;
    int *pa = &a;
    printf("%i\t%i\t%i\n", pa, *pa, &a);
    */

    // zapolnenie massiva
    int array[SIZE];
    init_massiv(array, SIZE);
    int *pArray = array;
    printf("Ukazatel': %i Massiv: %i\n", pArray, array);
    printf("Razimenovannie ukazatel': %i razimenov massiv: %i\n", *pArray, *array);
    printf("-----------------------------------\n");
    vyvod_massiva(array, SIZE);
    printf("-----------------------------------\n");
    vyvod_massiva(pArray, SIZE);
    putchar('\n');
    printf("-----------------------------------\n");
    int a = 0, b = 0, c = 0;
    printf("a = %i, b = %i, c = %i\n",a, b, c);
    ptr_func(&a, &b, &c);
    printf("a = %i, b = %i, c = %i\n",a, b, c);
    return 0;
}

void init_massiv(int massiv[], const int dlina_massiva)
{
    for (int i = 0; i < dlina_massiva; i++)
    {
        massiv[i] = rand() % 10;
    }
}

void vyvod_massiva(int massiv[], const int dlina_massiva){
    for(int i = 0; i < dlina_massiva; i++){
        printf("Adress %i elementa massiva = %i. Znachenie = %i\n", i+1, massiv + i, *(massiv + i));
    }
}

void ptr_func(int *pa, int *pb, int *pc){
    *pa = 100;
    *pb = 200;
    *pc = 300;
}