#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Напишите программу, которая считывает два целых неотрицательных числа,
    //разделённых пробелом. Программа должна вычислить их сумму S и вывести
    //произведение S на количество цифр в десятичной записи S.
    int a = 0, b = 0, S = 0;
    printf("Vvedite 2 chisla: \n");
    cin >> a >> b;
    S = a + b;
    int razmer = to_string(S).size();
    cout << razmer * S << endl;
    return 0;
}