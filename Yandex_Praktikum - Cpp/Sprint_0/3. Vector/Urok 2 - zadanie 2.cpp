#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> month_name = {
        "January"s,
        "February"s,
        "March"s,
        "April"s,
        "May"s,
        "June"s,
        "July"s,
        "August"s,
        "September"s,
        "October"s,
        "November"s,
        "December"s};
    int num_of_month;
    cin >> num_of_month;
    if((num_of_month < 1) || (num_of_month > 12)){
        cout << "Incorrect month"s;
    }
       else {
        cout << "There are "s << month_lengths[num_of_month - 1] << " days in "s << month_name[num_of_month - 1] << endl;
       }
    return 0;
}




/*
Улучшите предыдущую программу. Добавьте в неё следующие возможности:

    Нумерацию месяцев ведите не с нуля, а как в жизни: май — пятый месяц, декабрь — двенадцатый.
    Добавьте обработку ошибок. Если пользователь ввёл номер несуществующего месяца, выведите текст Incorrect month.
    Вместо сиротливого числа выведите полноценную фразу, например There are 31 days in January.

Для реализации последнего пункта заведите второй вектор типа vector<string>, в который нужно сложить названия месяцев на английском:

    January
    February
    March
    April
    May
    June
    July
    August
    September
    October
    November
    December

Формат входных данных:
Одно целое число — календарный номер месяца.

Формат выходных данных:
Фраза: There are {количество дней} days in {название месяца с заглавной буквы}. Точку в конце фразы не выводите.
Либо фраза: Incorrect month, если введён некорректный номер месяца.
В конце вывода, как всегда, endl.

Ограничения:
Решите задачу с использованием двух векторов и никак иначе.

Пример:

    Ввод: 5. Вывод: There are 31 days in May.
    Ввод: 2. Вывод: There are 28 days in February.
    Ввод: 0. Вывод: Incorrect month.
    Ввод: 100. Вывод: Incorrect month.

Точка не входит в вывод.
*/