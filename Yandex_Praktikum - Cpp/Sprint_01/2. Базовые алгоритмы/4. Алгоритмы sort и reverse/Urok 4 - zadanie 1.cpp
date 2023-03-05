#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, string>> people;
    int count;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        string name;
        int age;
        cin >> name >> age;
        // сохраните в вектор пар
        people.push_back(make_pair(age, name));
    }
    
    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());
    for(const auto &element : people){
        cout << element.second << endl;
    }
}




/*
Задание 1


Считайте количество людей, имя и возраст каждого. Выведите все имена с новой строки по старшинству — от старых к молодым.
Вектор пар сортируется лексикографически. Например, у вас есть вектор:

vector<pair<int, double>> values = {{5, -1.1}, {5, -1.0}, {1, 0.0}}; 

После сортировки значения будут в таком порядке:

{1, 0.0}
{5, -1.1} // 1 < 5
{5, -1.0}, // 5 == 5, -1.1 < -1.0 
*/




/*
// Решение от авторов:


#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
int main() {
    vector<pair<int, string>> people;
 
    int count;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        string name;
        int age;
        cin >> name >> age;
        people.push_back({age, name});
    }
 
    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());
 
    for (const auto& person : people) {
        cout << person.second << endl;
    }
}
*/