#include <iostream>
using namespace std;

template <typename T1, typename T2>
void sum(T1 a, T2 b)
{
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    sum(5, "ghbdtn");
    sum(5.5, 5.4);
    sum('5', '7');
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}