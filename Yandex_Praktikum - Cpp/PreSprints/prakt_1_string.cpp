#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
    Напишите программу, которая считывает имя и фамилию, разделённые пробелом,
    и выводит полное имя в формате <Фамилия>, <Имя>. Примените оператор сложения,
    чтобы соединить части строк в одну строку перед выводом, либо выведите их по
    отдельности в нужном порядке.
    */
    string firstname, secondname, newname;
    cin >> firstname >> secondname;
    cout << secondname << ' ' << firstname << endl;
    newname += secondname;
    newname += " "s;
    newname += firstname;
    cout << newname << endl;
    
    return 0;
}