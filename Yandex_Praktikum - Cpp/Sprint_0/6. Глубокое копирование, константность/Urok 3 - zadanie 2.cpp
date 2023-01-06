#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& sourse, vector<string>& destination) {
    for(auto& word : sourse){
        destination.push_back(word);
    }
    sourse.clear();
}




/*
Задание 2
Напишите функцию MoveStrings. Она принимает векторы строк source и destination и дописывает все строки из первого вектора в конец второго. После выполнения функции вектор source должен стать пустым.
===========================================================================
Чтобы очистить содержимое вектора, вызовите у него метод clear:

string query = "how to learn c++"s;
vector<string> query_words = SplitIntoWords(query);
query_words.clear();
// Теперь вектор query_words пуст. Метод empty вернёт true, метод size — 0. 
===========================================================================
Пример использования функции MoveStrings:

vector<string> source = {"how"s, "to"s, "learn"s};
vector<string> destination = {"c++"s};
MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "c++", "how", "to", "learn" именно в таком порядке 
*/