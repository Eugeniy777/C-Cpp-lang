#include <iostream>
#include <vector>
#include <string>

using namespace std;

// добавляем элемент вектора копированием
void call_copy(string &var, vector<string> &vec)
{
    vec.push_back(var);
}

// добавляем элемент вектора перемещением
// std::move приводит var к r-value типу
void call_move(string &&var, vector<string> &vec)
{
    vec.push_back(move(var));
}

vector<string> SplitIntoWords(const string &text)
{
    vector<string> words;
    string word;
    for (const char c : text)
    {
        if (c == ' ')
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }

    return words;
}

int main()
{
    string predl;
    getline(cin, predl);
    vector<string> vec = SplitIntoWords(predl);
    string word;
    cin >> word;
    call_copy(word, vec);
    call_move(word, vec);
    return 0;
}