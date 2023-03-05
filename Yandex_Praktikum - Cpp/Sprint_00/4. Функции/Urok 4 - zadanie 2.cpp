#include <iostream>
#include <string>
#include <vector>

using namespace std;

// определяет, будет ли строка s палиндромом
bool IsPalindrome(string s){
    for (int i = 0; i < s.size() / 2; ++i){
        if (s[i] != s[s.size() - i - 1]){
            return false;
        }
    }
    return true;
}

// создаёт вектор палиндромов не менее заданной длины
vector<string> PalindromeFilter(vector<string> words, int min_length){
    vector<string> Palindrome;
    for (auto word : words){
        if (IsPalindrome(word) && word.size() >= min_length){
            Palindrome.push_back(word);
        }
    }
    return Palindrome;
}

// разбивает предложение на слова, удаляя лишние пробелы
vector<string> SplitIntoWords(string text){
    vector<string> v;
    string word;
    for (int i = 0; i <= text.size(); ++i){
        if ((text[i] != ' ') && (text[i] != '\0')){
            word += text[i];
        }
        else if (((text[i] == ' ') || (text[i] == '\0')) && (text[i - 1] != ' ')){
            if (word == ""s){
                continue;
            }
            v.push_back(word);
            word = ""s;
        }
    }
    for (auto vec : v){
        cout << '[' << vec << ']' << endl;
    }
    return v;
}

int main(){
    string predl;
    cout << "Enter predlozhenie: " << endl;
    getline(cin, predl);
    int size_of_word;
    cout << "Enter MAX size of word: " << endl;
    cin >> size_of_word;
    for (auto ran : PalindromeFilter(SplitIntoWords(predl), size_of_word)){
        cout << ran << endl;
    }
    return 0;
}





/*
Задание 2
Напишите функцию, которая:

    называется PalindromeFilter,
    возвращает vector<string>,
    принимает vector<string> words и int min_length,
    возвращает из вектора words все строки-палиндромы длиной не меньше min_length.

Функция PalindromeFilter должна использовать вспомогательную функцию IsPalindrome, которая определяет, будет ли переданная ей строка палиндромом.

Примеры входных и выходных данных:
words			minLength	Результат
rotor, anna, kayak	5		rotor, kayak
rotor, anna		2		rotor, anna
racecar, bro, code	4		racecar

Как будет тестироваться ваш код:
Тренажёр проверит работу функций IsPalindrome и PalindromeFilter, вызывая их с различными входными данными и сравнивая результат этих функции с ожидаемыми значениями. Функция main будет заменена на версию из тренажёра.
*/




/*
Avtorskoe reshenie:

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*  объявляем функции для определения палиндрома
 * принимает строку s
 * возвращает true если строка s палиндром или false если строка s не палиндром */
bool IsPalindrome(string s) {
    /* начинаем цикл от 0 до половины размера строки с округлением вниз */
    for (int i = 0; i < s.size() / 2; ++i) {
        /* условие на выполнение блока:
         * i-ый элемент слева не равен  i-ыму элементу справа. */
        if (s[i] != s[s.size() - i - 1]) {
            /* это не палиндром.
             * возвращаем false */
            return false;
        }
    }
    /* если внутри цикла мы не вернули false значит это палиндром.
     * возвращаем true */
    return true;
}

/*  объявляем функцию
 * принимает вектор слов words и минимальную длину слова
 * возвращает вектор палиндромов длиной не меньше min_length */
vector<string> PalindromeFilter(vector<string> words, int min_length) {
    /*  объявляем вектор строк для хранения палиндромов длиной не меньше min_length  */
    vector<string> result;
    /*  проходим по всем словам из вектора words */
    for (string s : words) {
        /* условие на выполнение блока:
        * длина слова не меньше min_length и слово является палиндромом */
        if (s.size() >= min_length && IsPalindrome(s)) {
            /* FOR SUPPORT: добавляем слово в конец вектора палиндромов */
            result.push_back(s);
        }
    }
    /* возвращаем вектор палиндромов */
    return result;
}

int main() {
}

*/