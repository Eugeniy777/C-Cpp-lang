#include <iostream>
using namespace std;

int main() {
    int bill;
    int sum = 0;
    do {
        cin >> bill;
        if (bill > 0) {
            cout << "Income: " << bill << endl;
            sum += bill;
        }
    } while (bill != 0);
    cout << "Total income: " << sum << endl;
return 0;
}




/*
Написать программу для подсчёта чистой прибыли компании. Приходы и расходы она читает из cin, но суммирует только положительные суммы — приходы. Все отрицательные суммы игнорируются. Признаком конца программы будет счёт ноль.
В коде нельзя использовать оператор continue.
*/