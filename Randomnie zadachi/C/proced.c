#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define SIZE 10

void calculator();
void init_array(int array[], int size);

int main()
{
    srand(time(0));
    /*
    printf("Do you need a calculator? y - \"yes\", n - \"no\"\n");
    char answer = 0;
    scanf_s("%c", &answer);
    answer == 'y' ? calculator() : printf("Bye bye");
    */
    int size_array = 10;
    int *pointerr = malloc(size_array * sizeof(int));
    init_array(pointerr, size_array);
    printf("pointer[4] = %i\n", pointerr[5]);
    free(pointerr);
    return 0;
}

void calculator()
{
    printf("Vvedite 1st 4islo:\n");
    double first_4islo;
    scanf("%lf", &first_4islo);
    getchar();
    printf("Vvedite deystvie (+ - * / %%):\n");
    char deystvie;
    scanf_s("%c", &deystvie);
    getchar();
    printf("Vvedite 2st 4islo:\n");
    double second_4islo;
    scanf_s("%lf", &second_4islo);
    getchar();
    switch (deystvie)
    {
    case '+':
        printf("%.2lf %c %.2lf = %.2lf", first_4islo, deystvie, second_4islo, first_4islo + second_4islo);
        break;
    case '-':
        printf("%.2lf %c %.2lf = %.2lf", first_4islo, deystvie, second_4islo, first_4islo - second_4islo);
        break;
    case '*':
        printf("%.2lf %c %.2lf = %.2lf", first_4islo, deystvie, second_4islo, first_4islo * second_4islo);
        break;
    case '/':
        printf("%.2lf %c %.2lf = %.2lf", first_4islo, deystvie, second_4islo, first_4islo / second_4islo);
        break;
    case '%':
        printf("%i %c %i = %i", (int)first_4islo, deystvie, (int)second_4islo, (int)first_4islo % (int)second_4islo);
        break;
    default:
        printf(" Vy vveli ne vernoe znachenie");
    }
    exit(0);
}

void init_array(int array[], int size)
{
    // init array
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
        printf("array[%i] = %i\n", i + 1, *(array + i));
    }
    return;
}

