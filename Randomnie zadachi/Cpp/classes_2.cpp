#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
    int age;
    int weight;
    string name;

    void print()
    {
        cout << "Name " << name << "\nWeoght " << weight << "\nAge " << age << endl;
    }

private:
};

class Point
{
public:
    int x;
    int y;
    int z;
};

int main()
{
    Human first_human;
    first_human.age = 30;
    first_human.weight = 80;
    first_human.name = "Ivanov Ivan";

    first_human.print();
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}