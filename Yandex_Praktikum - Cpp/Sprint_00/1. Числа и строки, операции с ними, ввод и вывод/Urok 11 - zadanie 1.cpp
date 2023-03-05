#include <iostream>
#include <string>

using namespace std;

int main() {
    string ffirst, ssecond, tthird, ffourth, ffifth;
    cin >> ffirst >> ssecond >> tthird >> ffourth >> ffifth;
    cout << ffirst[0] << ssecond[0] << tthird[0] << ffourth[0] << ffifth[0];
    return 0;
}




/*
Считайте из стандартного ввода пять слов и выведите первые символы введённых строк слитно. Под словом понимается последовательность символов, таких как буквы, цифры, знаки препинания. Слова разделяются одним пробелом.

Примеры ввода-вывода:
Ввод:				Вывод:
apple banana cat dog eleven	abcde
a s d f g			asdfg
1 two 3 four 5			1t3f5

Как будет тестироваться ваш код:
Тренажёр подаст в стандартный поток ввода пять слов, разделённых пробелами, и сравнит вывод с ожидаемым.
*/