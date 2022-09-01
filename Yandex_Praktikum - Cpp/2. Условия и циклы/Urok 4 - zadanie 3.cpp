#include <iostream>
#include <string>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    if(a == b){
        cout << "The orange is divided into two equal parts"s << endl;
    }
    else if(a > b){
        cout << "Cut off "s << a - b << " from the first part"s << endl;
    }
    else{
        cout << "Cut off "s << b - a << " from the second part"s << endl;
    }
    return 0;
}




/*
Напишите код, который сравнивает половины апельсина. Программа считывает два вещественных числа — размеры половинок. Если числа равны, программа должна выводить на экран The orange is divided into two equal parts. Если первое число больше, пусть программа выводит Cut off X from the first part. Если больше второе число — пусть выводит Cut off X from the second part. Вместо X подставьте разницу в размере.
*/