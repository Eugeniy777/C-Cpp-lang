#include <stdio.h>

int sum(int var1, int var2);

int main()
{
    int a = 2, b = 2;
    int result = sum(a, b);
    printf("Result = %i\n", result);

    a = 100, b = 200;
    result = sum(a, b);
    printf("Result 2 = %i\n", result);
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}