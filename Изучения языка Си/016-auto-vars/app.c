#include <stdio.h>

int func_frame(int, int);

int main()
{
    int a = 0, b = 0;
    func_frame(a, b);
    printf("A = %i\n", func_frame(a, b));
    return 0;
}

int func_frame(int a, int b)
{
    auto int a = 1000;
    return a;
}