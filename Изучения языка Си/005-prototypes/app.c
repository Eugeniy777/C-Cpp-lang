#include <stdio.h>
#include <stdlib.h>

int func();

int main()
{
    puts("Vyvod funkcii MAIN\n");
    func();
    system("clear");
    system("whoami");
    puts("Vyvod funkcii MAIN\n");
    return 0;
}

int func()
{
    printf("Vyvod funkcii FUNC\n");
    return 0;
}