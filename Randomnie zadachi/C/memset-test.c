#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char Array[10];
    char *ptr1;
    char *ptr2;
    ptr1 = Array;
    //Обнуление блока памяти через имя массива
    // и имя указателя работает одинаково:
    memset(Array, 0, sizeof(Array));
    memset(ptr1, 0, 10);
    Array[0] = 'A'; // и так можно...
    ptr1[1] = 'B';  // и так тоже можно, теперь в массиве
    for (int i = 0; i < 10; i++)
    {
        printf("Array[%i] = %i\n", i, Array + i);
    }
    putchar('\n');
    // Array содержится строка "AB"...

    //Указателю можно присвоить как адрес массива,
    // так и значение указателя:
    ptr2 = Array + 1;
    printf("ptr2 = %i\n", ptr2);
    ptr2 = ptr1 + 2;
    printf("ptr2 = %i\n", ptr2);
    return 0;
}