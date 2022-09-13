#include <iostream>
#include <string>

using namespace std;

class MyClass
{
private:
    int size_of_arr;
    int *pointer;

public:
    // constructor (sozdaet massiv N elementov)
    MyClass(int size_of_arr)
    {
        this->size_of_arr = size_of_arr;
        pointer = new int[size_of_arr];
        for (int i = 0; i < size_of_arr; ++i)
        {
            pointer[i] = rand() % 10;
        }
        cout << "\nConstructor v chate\t"s << this << endl;
    }

    // construktor kopirovaniya
    MyClass(const MyClass &other)
    {
        this->size_of_arr = other.size_of_arr;
        this->pointer = new int[other.size_of_arr];
        for (int i = 0; i < other.size_of_arr; ++i)
        {
            this->pointer[i] = other.pointer[i];
        }
        cout << "\nConstructor kopirovaniya\t"s << this << endl;
    }

    // peregruzka operatora prisvaivaniya
    MyClass &operator=(const MyClass &other)
    {
        cout << "\nOperator prisvaivaniya\t"s << this << endl;
        if (this->pointer != nullptr)
        {
            delete[] this->pointer;
        }
        this->size_of_arr = other.size_of_arr;
        this->pointer = new int[other.size_of_arr];
        for (int i = 0; i < other.size_of_arr; ++i)
        {
            this->pointer[i] = other.pointer[i];
        }
        return *this;
    }
    ~MyClass()
    {
        delete[] pointer;
        cout << "\nDestructor v chate\t"s << this << endl;
    }

    void print_arr()
    {
        cout << "\nVyvodim dinamich massiv" << endl;
        for (int i = 0; i < this->size_of_arr; ++i)
        {
            cout << this->pointer[i] << ' ';
        }
        cout << endl;
    }
};

int main()
{
    MyClass a(15);
    a.print_arr();
    MyClass b = a;
    b.print_arr();
    MyClass c(5);
    c.print_arr();

    c = b = a;
    a.print_arr();
    b.print_arr();
    c.print_arr();
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}