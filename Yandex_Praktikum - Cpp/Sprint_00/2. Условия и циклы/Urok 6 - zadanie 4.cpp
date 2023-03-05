#include <iostream>
#include <string>

using namespace std;

int main() {
    string query;
    getline(cin, query);
    string word;
    for (int i = 0; i < query.size(); ++i) {
        if (query[i] != ' ') {
            word += query[i];
        }
        else{
            cout << '[' << word << ']' << endl;
            word = ""s;
        }
    }
    cout << '[' << word << ']' << endl;
    return 0;
}




/*
Считайте с терминала строку полностью до перевода строки. Индексация начинается с нуля. Каждое слово выведите заключёным в квадратные скобки. Например, если ввод был green parrot, вывод должен быть:

[green]
[parrot] 

Ограничения:
    Между словами — один пробел.
    Строка начинается со слова и заканчивается концом строки.
    В запросе ровно одна строка.
*/



/*
#include <iostream>
#include <string>

using namespace std;

int main() {
    string query;
    getline(cin, query);
    string word;
    for(int i = 0; i <= query.size(); ++i){
        if(query[i] != ' ' && query[i] != '\0'){
            word += query[i];
        }
        else{
            cout << '[' << word << ']' << endl;
            word = ""s;
        }
    }
}
*/