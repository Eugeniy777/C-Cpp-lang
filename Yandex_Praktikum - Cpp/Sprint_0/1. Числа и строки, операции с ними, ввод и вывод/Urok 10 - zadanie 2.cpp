#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    string secondname;
    cin >> name >> secondname;
    //getline(cin, name);
    cout << secondname << ", " << name;
/*
    string name;
    string second_name;
    cin >> name >> second_name;
    string full_name = second_name + ", "s + name;
    cout << full_name << endl;
*/
    return 0;
}




/*
Напишите программу, которая считывает имя и фамилию, разделённые пробелом, и выводит полное имя в формате <Фамилия>, <Имя>. Примените оператор сложения, чтобы соединить части строк в одну строку перед выводом, либо выведите их по отдельности в нужном порядке.
Формат ввода-вывода:
Имя и фамилия во вводе даны на одной строке и разделены одним пробелом. 
Для считывания имени и фамилии используйте cin >>.
Сначала выводится фамилия, затем запятая и пробел, потом выводится имя.

Ввод:				Вывод:
Ivan Ivanov			Ivanov, Ivan
Maria Petrova-Hohenzollern	Petrova-Hohenzollern, Maria
*/