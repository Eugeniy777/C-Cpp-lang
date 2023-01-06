#include <iostream>
#include <string>
using namespace std;

int main() {
    string color1, color2, color3, color0;
    cin >> color1 >> color2 >> color3 >> color0;
    if(color0 == color1) {
        cout << "Enter the house 1"s << endl;
    } else if(color0 == color2) {
        cout << "Enter the house 2"s << endl;
    } else if(color0 == color3){
        cout << "Enter the house 3"s << endl;
    } else {
        cout << "Seek somewhere else"s << endl;
    }
    return 0;
}




/*
Перед Зои три дома разного цвета. Ей известно, рядом с домом какого цвета видели последний раз её Пушистика. Дома имеют номера: 1, 2 и 3. Определите номер дома, с владельцем которого ей надо поговорить насчёт своего питомца.

Формат входных и выходных данных:
В стандартный поток ввода передаются четыре цвета: цвета трёх домов и цвет дома, рядом с которым видели Пушистика. Цвета разделяются одним пробелом. Гарантируется, что все три дома имеют разные цвета.
В стандартный поток вывода надо вывести строку Enter the house X — «Войти в дом X», где X — номер дома: 1, 2 или 3, рядом с которым видели Пушистика. Если среди домов нет дома нужного цвета, надо вывести строку Seek somewhere else — «Искать в другом месте».
После фразы выведите символ конца строки.

Примеры входных и выходных данных
Ввод:				Вывод:
red green blue red		Enter the house 1
white blue yellow yellow	Enter the house 3
red green blue black		Seek somewhere else
*/




/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    string house_color_1, house_color_2, house_color_3, target_house_color;
    cin >> house_color_1 >> house_color_2 >> house_color_3 >> target_house_color;
    
    int house_number = 0;
    if (target_house_color == house_color_1) {
        house_number = 1;
    } else if (target_house_color == house_color_2) {
        house_number = 2;
    } else if (target_house_color == house_color_3) {
        house_number = 3;
    }
    
    if (house_number != 0) {
        cout << "Enter the house "s << house_number << endl;
    } else {
        cout << "Seek somewhere else"s << endl;
    }
    return 0;
}
*/