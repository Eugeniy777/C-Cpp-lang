#include <iostream>
#include <string>
using namespace std;

class human
{
public:
    int age;
    double weight;
    string name;

    void Print()
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"s << endl;
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "Weight = " << weight << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"s << endl;
    }

private:
protected:
};

class point
{
private:
    int x;
    int y;

public:
    void Print()
    {
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
    }
    point()
    {
        x = 0;
        y = 0;
        cout << this << " constructor"s << endl;
    }
    // konstruktor
    point(int valueX, int valueY)
    {
        x = valueX;
        y = valueY;
        cout << this << " constructor"s << endl;
    }
    // setter - ustanavlivaet znachenie v pole
    void SetX(int valueX)
    {
        x = valueX;
    }
    void SetY(int y)
    {
        this->y = y;
    }

    // getter - vozvraschaet znachenie iz polya
    int GetX()
    {
        return x;
    }
};

class CoffeeGrinder
{
private:
    bool CheckVoltage()
    {
        return true;
    }

public:
    void Start()
    {
        if (CheckVoltage())
        {
            cout << "Vjuhhh!!!"s << endl;
        }
        else
        {
            cout << "Beep Beep"s << endl;
        }
    }
};

class MyClass
{
private:
    int *data;
    int Size;

public:
    MyClass(int size)
    {
        this->Size = size;
        this->data = new int[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = i;
        }
        cout << " Vyzvalsya constructor"s << endl;
    }
    MyClass(const MyClass &other)
    {
        this->Size = other.Size;
        this->data = new int[other.Size];
        for (int i = 0; i < other.Size; ++i)
        {
            this->data[i] = other.data[i];
        }
        cout << " Vyzvalsya constructor kopirovaniya"s << endl;
    }

    ~MyClass()
    {
        delete[] data;
        cout << "Vyzvalsya destructor"s << endl;
    }
};

int main()
{
    MyClass a(10);
    MyClass b(a);

    /*----------------------------------*/
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}