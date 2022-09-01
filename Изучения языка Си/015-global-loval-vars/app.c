#include <stdio.h>

int global = 100;

int function()
{
    puts("function: function");

    int local = 200;

    printf("Global: %i\n", global);
    printf("Local: %i\n", local);

    return 0;
}

int main()
{
    puts("function: main");

    int local = 300;

    printf("Global: %i\n", global);
    printf("Local: %i\n", local);
    function();
    return 0;
}