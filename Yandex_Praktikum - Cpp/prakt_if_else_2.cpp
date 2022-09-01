#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Программа работает, но слово “document” всегда пишет во множественном числе —
    //например, 1 documents found. Отредактируйте код.
    //Если на вход дан 0, пусть программа выводит No documents found,
    //если 1 — One document found.
    //Во всех остальных случаях программа должна выводить
    //<число документов> documents found.

    int a = 0;
    printf("Vvedite kol-vo dokumentov: \n");
    cin >> a;
    if (a == 0)
    {
        cout << "No documents found"s << endl;
    }
    else if (a == 1)
    {
        cout << "One document found"s << endl;
    }
    else
    {
        string otvet = to_string(a) + " documents found"s;
        cout << otvet << endl;
    }
    return 0;
}