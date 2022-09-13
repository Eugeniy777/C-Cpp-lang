#include <iostream>
#include <list>
 
int main()
{
    std::list<int> numbers { 1, 2, 3, 4, 5 };
 
    int first = numbers.front();  // 1
    int last = numbers.back();  // 5
 
    // перебор в цикле
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
    
    // перебор с помощью итераторов
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
    return 0;
}