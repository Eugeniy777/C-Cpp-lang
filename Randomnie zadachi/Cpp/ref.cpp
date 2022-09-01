#include <iostream>
using namespace std;

void foo(int a);
void foo_ref(int &b);
void foo_ptr(int *c);

int main()
{
    int a = 0, b = 0, c = 0;
    printf("%i %i %i\n", a, b, c);
    foo(a);
    foo_ref(b);
    foo_ptr(&c);
    printf("%i %i %i\n", a, b, c);
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}

void foo(int a)
{
    a = 1;
}

void foo_ref(int &b)
{
    b = 2;
}

void foo_ptr(int *c)
{
    *c = 3;
}