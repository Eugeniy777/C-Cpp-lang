#include <iostream>
#include <string>

using namespace std;

int main() {
    int document_count;
    cin >> document_count;
    string message = to_string(document_count) + " documents found"s;
    if(document_count == 0){
    cout << "No documents found"s;
    }
    else if(document_count == 1){
    cout << "One document found"s;
    }
    else{
    cout << message << endl;
    }
return 0;
}




/*
В предыдущей теме вы написали код программы, которая:

    считывает число — количество документов;
    выводит на экран, сколько документов найдено: <число документов> documents found.

Программа работает, но слово “document” всегда пишет во множественном числе — например, 1 documents found. Отредактируйте код. Если на вход дан 0, пусть программа выводит No documents found, если 1 — One document found. Во всех остальных случаях программа должна выводить <число документов> documents found.

Пример:
Ввод	Вывод
0	No documents found
1	One document found
5	5 documents found
*/