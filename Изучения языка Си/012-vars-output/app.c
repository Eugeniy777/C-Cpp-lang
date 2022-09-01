#include <stdio.h>

// echo %errorlevel% - kod otveta na Windows

int func_three();
int func_four();

int main()
{
    puts("Welcome to variables!");

    // obyavlenie i initialization by Literal
    int v1 = 1;
    int v2 = 2;

    printf("v1 + v2 = %i\n", v1 + v2);

    // obyavlenie i initialization and ob'yavlenie by funtion
    int v3 = func_three();
    int v4 = func_four();

    int v7 = v3 + v4;

    printf("%i + %i = %i\n", v3, v4, v7);

    // v etih peremennyh lezhit musor
    // int v5, v6, v7;

    int a = 0, b = 0, c = 0;

    printf("a: %d\nb: %d\nc: %d\n", a, b, c);

    return 0;
}

int func_three()
{
    return 3;
}

int func_four()
{
    return 4;
}
