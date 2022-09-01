#include <iostream>
using namespace std;

int main() {
int h, m1, m2, s1, s2, N; //N-вспомогательная переменная
    cin >> N;
    
h = (N / 3600) % 24;        //находим кол-во часов в сутках состоящее из данных секунд
m1 = (N / 60) % 60 / 10;    //находим кол-во десятков минут
m2 = (N / 60) % 60 % 10;    //находим кол-во секунд после десятков
s1 = N % 60 / 10;            //находим кол-во десятков секунд
s2 = N % 60 % 10;
    
cout << h << ":" << m1 << m2 << ":" << s1 << s2;
    
  return 0;
}






/*
Электронные часы

Электронные часы показывают время в формате h:mm:ss (от 0:00:00 до 23:59:59), то есть сначала записывается количество часов, потом обязательно двузначное количество минут, затем обязательно двузначное количество секунд. Количество минут и секунд при необходимости дополняются до двузначного числа нулями.

С начала суток прошло N секунд. Выведите, что покажут часы.

Формат входных данных:
На вход дается натурально число N, не превосходящее 107 10^7 107 (10000000).

Формат выходных данных:
Выведите ответ на задачу.
*/