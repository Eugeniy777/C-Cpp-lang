#include <iostream>
#include <string>

using namespace std;

int main() {
    int a = 5;
    int b;
    do {  
        cout << "Guess the number: "s << endl;  
        cin >> b;
    } while (a != b);
    cout << "You are right!"s << endl;
return 0;
}




/*
Игрок должен вводить число, пытаясь угадать его. Верный ответ — 5. Если число 5 угадано, программа выводит "You are right!". Если пользователь ошибся, программа выводит "Guess the number: ".
*/