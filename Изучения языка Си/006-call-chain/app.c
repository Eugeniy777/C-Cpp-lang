#include <stdio.h>
#include <stdlib.h>

int func1();

int func2();

int func3();

int main()
{
    // instructions
    func1();
    return 0;
}

int func3()
{
    puts("otrabotala func3");
    return 0;
}

int func2()
{
    puts("otrabotala func2");
    func3();
    func3();
    return func3();
}

int func1()
{
    puts("otrabotala func1");
    return func2();
}