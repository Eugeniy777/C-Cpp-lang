#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LENGTH 10
#define SEPARATOR "---------------------"

void calculator();
void init_and_print_arrays(int[], int[], const int, char[]);
void sort_arrays(int[], int[], const int, char[]);
void change_arrays(int[], int[], const int, char[]);

int main()
{
    srand(time(0));
    printf("Are you need a calc? \npress \"y\" - for \"yes\" and \"n\" - for \"no\"\n");
    char answer;
    scanf_s("%c", &answer);
    getchar();
    if (answer == 'y')
        calculator();
    // sozdaem 2 massiva
    int array_1[LENGTH];
    int array_2[LENGTH];
    //init and print arrays
    init_and_print_arrays(array_1, array_2, LENGTH, "Vyvodim massiv 1 and massiv 2: ");
    //sort arrays
    sort_arrays(array_1, array_2, LENGTH, "Sortiruem massiv 1 and massiv 2: ");
    //menyaem arrays mestami
    change_arrays(array_1, array_2, LENGTH, "Menyaem massiv 1 and massiv 2 mestami: ");
    return 0;
}

void calculator()
{
    printf("Press 1st number: \n");
    double number_1;
    scanf_s("%lf", &number_1);
    getchar();
    printf("Press action (\"+\" \"-\" \"*\" \"/\" \"%%\")\n");
    char action;
    scanf_s("%c", &action);
    getchar();
    printf("Press 2nd number: \n");
    double number_2;
    scanf_s("%lf", &number_2);
    getchar();
    puts(SEPARATOR);
    switch (action)
    {
    case '+':
        printf("%.2f %c %.2f = %.2f", number_1, action, number_2, number_1 + number_2);
        break;
    case '-':
        printf("%.2f %c %.2f = %.2f", number_1, action, number_2, number_1 - number_2);
        break;
    case '*':
        printf("%.2f %c %.2f = %.2f", number_1, action, number_2, number_1 * number_2);
        break;
    case '/':
        printf("%.2f %c %.2f = %.2f", number_1, action, number_2, number_1 / number_2);
        break;
    case '%':
        printf("%.2f %c %.2f = %.2f", number_1, action, number_2, fmod(number_1, number_2));
        break;
    default:
        printf("Vy vveli bred");
    }
    return;
}

void init_and_print_arrays(int massiv_1[], int massiv_2[], const int dlina, char text[])
{
    puts(text);
    // zapolnyaem i vyvodim massivy
    for (int i = 0; i < dlina; i++)
    {
        massiv_1[i] = rand() % 100;
        massiv_2[i] = rand() % 100;
        printf("Massiv_1[%2i] = %2i\t\tMassiv_2[%2i] = %2i\n", i + 1, massiv_1[i], i + 1, massiv_2[i]);
    }
    return;
}

void sort_arrays(int massiv_1[], int massiv_2[], const int dlina, char text[])
{
    puts(text);
    // sortirovka massivov
    for (int i = 0; i < dlina - 1; i++)
    {
        for (int y = i + 1; y < dlina; y++)
        {
            if (massiv_1[i] > massiv_1[y])
            {
                int temp = massiv_1[i];
                massiv_1[i] = massiv_1[y];
                massiv_1[y] = temp;
            }
            if (massiv_2[i] > massiv_2[y])
            {
                int temp = massiv_2[i];
                massiv_2[i] = massiv_2[y];
                massiv_2[y] = temp;
            }
        }
    }
    for (int i = 0; i < dlina; i++)
    {
        printf("Massiv_1[%2i] = %2i\t\tMassiv_2[%2i] = %2i\n", i + 1, massiv_1[i], i + 1, massiv_2[i]);
    }
    return;
}

void change_arrays(int massiv_1[], int massiv_2[], const int dlina, char text[])
{
    puts(text);
    for (int i = 0; i < dlina; i++)
    {
        int temp = massiv_1[i];
        massiv_1[i] = massiv_2[i];
        massiv_2[i] = temp;
        printf("Massiv_1[%2i] = %2i\t\tMassiv_2[%2i] = %2i\n", i + 1, massiv_1[i], i + 1, massiv_2[i]);
    }
    return;
}

