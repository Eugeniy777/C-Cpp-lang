#include <cstdint>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    const auto min = numeric_limits<int64_t>::min();  // минимальное значение типа int64_t
    const auto max = numeric_limits<uint64_t>::max(); // максимальное значение типа uint64_t

    // выведите 5 чисел
    cout << min << '\n' << max << '\n' << min + max << '\n' << min * 2 << '\n' << max * 2 << endl;
    return 0;
}




/*
Задание 1


Пощупайте переполнение типов int64_t и uint64_t на простом примере.
Запомните в переменную min минимальное значение типа int64_t, а в переменную max — максимальное значение uint64_t.
Никак не преобразуя типы, выведите 5 чисел, каждое на новой строке:

    min
    max
    Сумму min и max
    Удвоенный min
    Удвоенный max

Посмотрите на вывод — один из результатов вычислений будет неожиданным.
*/




/*
// Решение от авторов:


#include <cstdint>
#include <iostream>
#include <limits>
 
using namespace std;
 
int main() {
    const auto min = numeric_limits<int64_t>::min();
    const auto max = numeric_limits<uint64_t>::max();
 
    cout << min << endl;
    cout << max << endl;
    cout << min + max << endl;
    cout << 2 * min << endl;
    cout << 2 * max << endl;
 
    return 0;
}
*/