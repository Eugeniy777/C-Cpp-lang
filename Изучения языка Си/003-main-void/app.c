#include <stdio.h>
#include <stdlib.h>

/* @TODO Описание задачи */
/* @return^ void */

void func();

int main()
{
    puts("void main!");
    func();
    printf("hello dear %d\n", 700 + 70 + 7);
    return 0;
}

void func()
{
    printf("HELLO WORLD\n");
}
