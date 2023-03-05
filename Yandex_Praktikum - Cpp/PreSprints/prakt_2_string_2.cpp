#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Напишите программу, которая считывает число (количество документов)
    //и выводит на экран <число документов> documents found.
    //Сначала сформируйте строку с ответом, только потом выведите её на экран целиком.
    int a = 0;
    printf("Vvedite kol-vo dokumentov: \n");
    cin >> a;
    string otvet = to_string(a) + " documents found"s;
    cout << otvet << endl;
    return 0;
}