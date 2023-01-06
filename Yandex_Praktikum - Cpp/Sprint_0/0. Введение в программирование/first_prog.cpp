#include <vector>
#include <string>
#include <iostream>
 
using namespace std;
 
int FindInVector(vector<string> haystack, string needle) {
    int index = 0;
    for (string s : haystack) {
        if (s == needle) {
            return index;
        }
        index += 1;
    }
    return -1;
}
 
// Не меняйте следующие функции
void PrintVector(vector<string> v) {
    bool is_first = true;
    for (string s : v) {
        if (!is_first) {
            cout << ", "s;
        }
        cout << s;
        is_first = false;
    }
}
 
void TestFind(vector<string> haystack, string needle) {
    int result = FindInVector(haystack, needle);
    
    if (result < 0 ) {
        cout << needle << " not found in "s;
        PrintVector(haystack);
        cout << endl;
    } else if (result < haystack.size() && haystack[result] == needle) {
        cout << needle << " found at "s << result << endl;
    } else {
        cout << "Incorrect result"s << endl;
    }
}
 
int main() {
    TestFind({"zero"s, "one"s, "two"s, "three"s, "four"s, "five"s}, "four"s);
    TestFind({"one"s, "two"s, "three"s}, "four"s);
    TestFind({"to"s, "be"s, "or"s, "not"s, "to"s, "be"s}, "be"s);
}
 
 
-----------------------------------------------------------------------------------------------------------
 
 
// functions.cpp