#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1, s2 = ""; 
    getline(cin, s1);
    // idyom s kontsa stroki
    for (int i = s1.size() - 1; i >= 0; i--) 
        s2 = s2 + s1[i];
    if (s1 == s2) 
        cout << "yes";
    else 
        cout << "no";
    return 0;
}




/*
По данной строке определите, является ли она палиндромом (то есть, читается одинаково как слева-направо, так и справа-налево).

Входные данные:
На вход подается 1 строка без пробелов.

Выходные данные:
Необходимо вывести yes, если строка является палиндромом, и no в противном случае.
*/