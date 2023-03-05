#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
// #include <cctype>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<string> words;
    for(int i = 0; i < N; ++i){
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    sort(words.begin(), words.end(), [](string lhs, string rhs)
         { return lexicographical_compare(lhs.begin(), lhs.end(),
                                          rhs.begin(), rhs.end(), [](const char lt, const char rt)
                                          { return tolower(lt) < tolower(rt); }); });
    for (auto w : words)
    {
        cout << w << ' ';
    }
    cout << endl;
    return 0;
}




/*
Задание 1


В стандартном потоке дана одна строка, которая состоит из числа N и следующего за ним набора S из N слов. Число отделено от слов пробелом.
Отсортируйте набор слов S в алфавитном порядке по возрастанию, игнорируя регистр букв. Выведите их в стандартный поток вывода через пробел. При сравнении слов цифры должны предшествовать буквам: слово «R2D2» находится после слова «R259», так как цифра 5 предшествует любой из букв.
После последнего слова также выведите пробел, а затем перевод строки.
Ознакомьтесь с функцией tolower и алгоритмом lexicographical_compare, чтобы отсортировать слова в алфавитном порядке без учета регистра символов.

Как будет тестироваться ваш код
Гарантируется, что входные данные программы удовлетворяют следующим услови¤м:

    0 <= N <= 1000;
    1 <= |S[i]| <= 15;
    каждое слово S[i] содержит только цифры, заглавные и строчные буквы английского алфавита;
    в наборе слов S нет слов, которые отличаются только регистром символов, например: «apple» и «Apple».

Пример

Ввод

8 quantity AMOUNT Selection Search 4ever music Mickey market 

Вывод 

4ever AMOUNT market Mickey music quantity Search Selection 

*/




/*
// Решение от авторов:


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    /* FOR SUPPORT: объявляем переменную для хранения количество чисел и инициализируем нулем */
    int n = 0;
    /* FOR SUPPORT: объявляем строку */
    string val;
    /* FOR SUPPORT: объявляем вектор строк */
    vector<string> v;
    /* FOR SUPPORT: считываем число */
    cin >> n;
    /* FOR SUPPORT: выделяем память под место для n элементов */
    v.reserve(n);
    /* FOR SUPPORT: запускаем цикл на n итераций */
    for (int i = 0; i < n; ++i) {
        /* FOR SUPPORT: считываем строку */
        cin >> val;
        /* FOR SUPPORT: добавляем строку в конец вектора */
        v.push_back(val);
    }
    /* FOR SUPPORT: begin() вернет начало контейнера\строки end() вернет конец контейнера\строки
     * передаем в std::sort 3-им параметром лямбда-функцию которая сравнивает две строки в лексикографически */
    sort(begin(v), end(v), [](const string& l, const string& r) {
            return lexicographical_compare(
                begin(l), end(l),
                begin(r), end(r),
                /* FOR SUPPORT: передаем еще одну лямбда-функцию которая сравнивает символы без учета регистра */
                [](char cl, char cr) { return tolower(cl) < tolower(cr); }
            );
        }
    );
    /* FOR SUPPORT: запускаем цикл для обхода вектора */
    for (int i = 0; i < v.size(); ++i) {
        /* FOR SUPPORT: выводим i-ый элемент вектора */
        cout << v[i] << ' ';
    }
    /* FOR SUPPORT: выводим перевод строки */
    cout << endl;
}
*/