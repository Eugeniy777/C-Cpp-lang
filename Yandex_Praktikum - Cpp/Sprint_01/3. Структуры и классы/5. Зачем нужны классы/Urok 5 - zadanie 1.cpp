#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class SearchServer {
    // Содержимое раздела public: доступно для вызова из кода вне класса
public:
    int GetStopWordsSize() const {
        return stop_words_.size();
    }

    // Содержимое раздела private: доступно только внутри методов самого класса
private:
    struct DocumentContent {
        int id = 0;
        vector<string> words;
    };

    DocumentContent documents_;
    
    set<string> stop_words_;
};

int GetStopWordsSize(const SearchServer& server) {
    return server.GetStopWordsSize();
}

int main() {
    SearchServer server;
    cout << GetStopWordsSize(server) << endl;

}




/*
Задание 1


Посмотрите, как работает тип данных class. 

    Объявите в функции main переменную типа SearchServer и обратитесь к одному из её полей — например, выведите количество стоп-слов во множестве. Вы получите ошибку компиляции об обращении к приватному полю. Это нормально.

Подчёркивания в названиях необязательны. Но они показывают, что обратиться к полям напрямую не получится:

/*
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
class SearchServer {
private:
    struct DocumentContent {
        int id = 0;
        vector<string> words;
    };
    DocumentContent documents_;
    set<string> stop_words_;
};

*/

    Напишите прямо внутри класса функцию GetStopWordsSize, которая будет возвращать размер множества стоп-слов. Такая функция называется метод. Так как метод находится внутри класса, он имеет доступ к его полям. Чтобы метод можно было вызвать снаружи класса, мы снабдили его меткой public: в заготовке кода .
    Сделайте свободную функцию GetStopWordsSize. Вызовите в ней вышеописанный метод у переданного в функцию по константной ссылке сервера.

Как будет тестироваться ваш код
Тренажёр проверит, что функция GetStopWordsSize и класс SearchServer работают так, как требуется в задании.
*/




/*
Решение от авторов:


#include <iostream>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
 
class SearchServer {
public:
    int GetStopWordsSize() const {
        return stop_words_.size();
    }
 
private:
    struct DocumentContent {
        int id = 0;
        vector<string> words;
    };
 
    DocumentContent documents_;
    set<string> stop_words_;
};
 
int GetStopWordsSize(const SearchServer& server) {
    return server.GetStopWordsSize();
}
 
int main() {
    SearchServer server;
    cout << GetStopWordsSize(server) << endl;
}
*/