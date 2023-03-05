#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ReadNumbers()
{
    int count;
    cin >> count;

    vector<int> numbers;
    for (int i = 0; i < count; ++i)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    return numbers;
}

void PrintNumbers(const vector<int> &numbers)
{
    for (auto number : numbers)
    {
        cout << number << " "s;
    }
}

int main()
{
    vector<int> numbers = ReadNumbers();

    sort(numbers.begin(), numbers.end(), [](int n1, int n2)
         {
        /*
           Напишите тело лямбда-функции самостоятельно.
           Сначала должны располагаться чётные числа в порядке возрастания,
           а следом за ними — нечётные числа в порядке убывания
        */
       if((n1 % 2 == 0) && (n2 % 2 == 0)){
        return n1 < n2;
       }
       if((n1 % 2 == 0) && (n2 % 2 != 0)){
        return true;
       }
       if((n1 % 2 != 0) && (n2 % 2 == 0)){
        return false;
       }
        return n1 > n2;
       }
       );

    PrintNumbers(numbers);
}




/*
Задание 1


Как и в обычных функциях, в лямбда-функциях разрешается использовать ветвления, циклы и вызовы других функций. Потренируйтесь в работе с такими функциями и напишите программу, которая считывает из стандартного ввода неотрицательное целое число N, за которым следуют N целых чисел, разделённых одним пробелом. Эти числа должны быть отсортированы в следующем порядке:

    сначала чётные числа по возрастанию,
    затем нечётные числа по убыванию.

Отсортированные числа должны быть выведены в стандартный поток. После каждого числа, включая последнее, должен быть выведен один пробельный символ. Если число N равно нулю, программа не должна считывать другие числа и выводить что-либо в поток вывода.
Код ввода и вывода чисел уже дан в заготовке. Напишите тело лямбда-функции, переданной в алгоритм sort.

Примеры входных и выходных данных:

Ввод:

11 4 6 3 2 7 5 8 9 2 1 5  

Вывод:

2 2 4 6 8 9 7 5 5 3 1  

Ввод:

0 

Вывод:

Как будет тестироваться ваш код
Тренажёр подаст на вход программе различные варианты входных данных и сравнит вывод программы с ожидаемым значением. Гарантируется, что число N будет неотрицательным, а за ним будут следовать ровно N целых чисел, разделённых пробелами.
*/




/*
// Решение от авторов:


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ReadNumbers()
{
    int count;
    cin >> count;

    vector<int> numbers;
    for (int i = 0; i < count; ++i)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    return numbers;
}

void PrintNumbers(const vector<int> &numbers)
{
    for (auto number : numbers)
    {
        cout << number << " "s;
    }
}

int main()
{
    vector<int> numbers = ReadNumbers();

    sort(numbers.begin(), numbers.end(),
         [](int n1, int n2)
         {
             const bool n1_is_even = n1 % 2 == 0;
             const bool n2_is_even = n2 % 2 == 0;
             if (n1_is_even && n2_is_even)
             { // n1 и n2 — чётные
                 // Чётные числа сортируются по возрастанию
                 return n1 < n2;
             }
             if (n1_is_even)
             {                // n1 — чётное, n2 — нечётное
                 return true; // чётные числа должны предшествовать нечётным
             }
             if (n2_is_even)
             {                 // n1 — нечётное, n2 — чётное
                 return false; // нечётные числа следуют за чётными
             }
             // n1 и n2 — нечётные
             return n1 > n2; // Нечётные числа сортируются по убыванию
         });

    PrintNumbers(numbers);
}
*/