#include <stdio.h>

// echo %errorlevel% - kod otveta na Windows

int func_one();
int func_two();

int func_two()
{

    return 2;
}

int func_one()
{

    return 1;
}

int main()
{
    int one = func_one();
    int two = func_two();
    int sum = one + two;
    printf("func_one + func_two = %d\n", sum);
    return 0;
}