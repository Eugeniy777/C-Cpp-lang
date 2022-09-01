#include <iostream>
#include <string>

using namespace std;

int main() {
    string first_book;
    string second_book;
    string third_book;
    getline(cin, first_book);
    getline(cin, second_book);
    getline(cin, third_book);
    cout << third_book << '\n';
    cout << second_book << '\n';
    cout << first_book << '\n';
    return 0;
}




/*
Напишите программу, которая считывает названия трёх книг по одному в строке и выводит их в обратном порядке, тоже по одному в строке. Название книги может состоять из нескольких слов.

Ввод:
Moby Dick
The Tiger Who Came to Tea
Harry Potter and the Deathly Hallows

Вывод:
Harry Potter and the Deathly Hallows
The Tiger Who Came to Tea
Moby Dick
*/