#include <iostream>
#include <vector>

using namespace std;

int main(){
vector <int> five_nums = {0, 7, 15, 4, 11};
int temp = five_nums[4];
five_nums[4] = five_nums[0];
five_nums[0] = temp;
temp = five_nums[3];
five_nums[3] = five_nums[1];
five_nums[1] = temp;
return 0;
}





/*

Задание 2
Дан вектор five_nums из пяти чисел типа int. Переставьте его элементы так, чтобы они шли в обратном порядке.
Требования

    Вектор объявлять не нужно. Считайте, что переменная уже дана.
    Ничего не выводите в поток.
    Измените элементы вектора так, чтобы 0-й и последний поменялись местами и т. д.

Пример
Если вектор содержит числа 100, 28, 37, 66, 16536, после работы вашей программы они должны идти в таком порядке: 16536, 66, 37, 28, 100.

*/