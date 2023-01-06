#include <iostream>
#include <vector>

using namespace std;

int main(){
vector <int> some_vector = {0, 7, 15, 4, 11};
vector <int> reversed_vector;
// vyvodim some_vector
for(auto i : some_vector){
    cout << i << ' ';
}
cout << '\n';
// vyvodim reversed_vector
for(auto i : reversed_vector){
    cout << i << ' ';
}
// menyaem mestami
for(int i = some_vector.size(); i > 0; --i){
    reversed_vector.push_back(some_vector[i-1]);
    some_vector.pop_back();
}
// vyvodim some_vector
for(auto i : some_vector){
    cout << i << ' ';
}
cout << '\n';
// vyvodim reversed_vector
for(auto i : reversed_vector){
    cout << i << ' ';
}
return 0;
}



/*
Задание 2
Вектор some_vector содержит от нуля до четырёх значений, а вектор reversed_vector — ни одного. Перенесите элементы из вектора some_vector в reversed_vector. В reversed_vector они должны расположиться в обратном порядке.
При решении может возникать дублирование кода. Далее в курсе вы узнаете, как и зачем его избегать.
Ограничения

    Не создавайте переменные some_vector и reversed_vector. Считайте, что они уже даны изначально.
    Программа должна работать с векторами типа int.
    Ничего не выводите в cout.

Пример
До работы программы:

    Содержимое вектора some_vector — числа 2, 4, 8, 16.
    Содержимое вектора reversed_vector — пусто.

После работы программы:

    Содержимое вектора some_vector — пусто.
    Содержимое вектора reversed_vector — числа 16, 8, 4, 2.

До работы программы:

    Содержимое вектора some_vector — числа 13, -128.
    Содержимое вектора reversed_vector — пусто.

После работы программы:

    Содержимое вектора some_vector — пусто.
    Содержимое вектора reversed_vector — числа -128, 13.
*/



// avtorskoe reshenie
/*
if (some_vector.size() > 0) {
    int last = some_vector[some_vector.size() - 1];
    reversed_vector.push_back(last);
    some_vector.pop_back();
}
if (some_vector.size() > 0) {
    int last = some_vector[some_vector.size() - 1];
    reversed_vector.push_back(last);
    some_vector.pop_back();
}
if (some_vector.size() > 0) {
    int last = some_vector[some_vector.size() - 1];
    reversed_vector.push_back(last);
    some_vector.pop_back();
}
if (some_vector.size() > 0) {
    int last = some_vector[some_vector.size() - 1];
    reversed_vector.push_back(last);
    some_vector.pop_back();
}
*/