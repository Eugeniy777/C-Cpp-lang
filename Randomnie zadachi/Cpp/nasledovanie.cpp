#include <iostream>
#include <string>

using namespace std;

class human
{
public:
    string name;
};

class student : public human
{
public:
    string group;
};

class professor : public human
{
public:
    string subject;
};

int main()
{
    student first;
    first.name;
    return 0;
}
