#include <iostream>
using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    x/=100;
    y/=100;
    if(n > a && n <= b){
        cout << (n = n - n * x);
    }
    else if(n > b){
        cout << (n = n - n * y);
    }
    else{
        cout << n;
    }

/*
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if(n > b){
        n = n - n * (y / 100);
        cout << n << endl;
    }
    else if(n > a){
        n = n - n * (x / 100);
        cout << n << endl;
    }
    else{
        cout << n << endl;
    }
*/
    return 0;
}




/*
Вы покупаете смартфон в магазине с гибкой системой скидок. Если исходная стоимость смартфона больше A рублей, на неё устанавливается скидка в X процентов. Если исходная стоимость смартфона больше B рублей, скидка составит Y процентов.
На вход программе даны пять вещественных чисел: N, A, B, X, Y.
N — исходная стоимость товара. Число A меньше числа B.
Выведите стоимость покупки смартфона с учётом скидки.

Пример
Ввод			Вывод
100 110 120 5 10	100
115 110 120 5 10	109.25
150 110 120 5 12.5	131.25
*/


/*
// variant 2

    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if(n > b){
        n = n - n * (y / 100);
        cout << n << endl;
    }
    else if(n > a){
        n = n - n * (x / 100);
        cout << n << endl;
    }
    else{
        cout << n << endl;
    }
*/