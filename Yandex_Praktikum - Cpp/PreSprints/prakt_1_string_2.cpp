#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Напишите программу, которая считывает названия трёх книг 
    //по одному в строке и выводит их в обратном порядке, тоже по одному в строке. 
    //Название книги может состоять из нескольких слов.

    string first_book, second_book, third_book, all_books;
    getline(cin, first_book);
    getline(cin, second_book);
    getline(cin, third_book);
    cout << third_book << '\n' << second_book << '\n' << first_book << endl;
    return 0;
}