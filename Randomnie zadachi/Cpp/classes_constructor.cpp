#include <iostream>
#include <time.h>
using namespace std;

class MyClass
{
private:
    int x;
    int *data;

public:
    MyClass(int size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = rand() % 10;
            // cout << data[i] << " " << *(data + i) << " " << data + i << endl;
        }
        this->x = 0;
    }

    int setX(int x)
    {
        this->x = x;
        return x;
    }

    ~MyClass()
    {
        delete[] data;
    }
    void print_Array(int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " " << *(data + i) << " " << data + i << endl;
        }
        // cout << "data = " << *data << " *data = " << data << endl;
    }
    void print()
    {
        cout << x << endl;
    }
};

int main()
{
    srand(time(0));
    int size = 5;
    MyClass A(10);
    A.print_Array(size);
    A.setX(15);
    A.print();

    // MyClass B(7);
    // B.print(size);
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}