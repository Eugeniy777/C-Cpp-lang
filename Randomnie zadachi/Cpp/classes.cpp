#include <iostream>
#include <string>
using namespace std;

class Human{
    public:
    int age;
    int weight;
    string name;
};
int main(){
    Human first_human;
    first_human.age = 30;
    first_human.name = "Ivanov Ivan Ivanovich";
    first_human.weight = 100;

    cout << first_human.age << endl;
    cout << first_human.name << endl;
    cout << first_human.weight << endl;

    Human second_human;
    second_human.age = 19;
    second_human.name = "Noname";
    second_human.weight = 59;

    cout << second_human.age << endl;
    cout << second_human.name << endl;
    cout << second_human.weight << endl;
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}