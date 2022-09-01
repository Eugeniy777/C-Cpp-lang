#include <stdio.h>

void proc()
{
    static int counter = 0;
    ++counter;
    printf("counter: %i\n", counter);
}

int main()
{
    proc();
    proc();
    return 0;
}