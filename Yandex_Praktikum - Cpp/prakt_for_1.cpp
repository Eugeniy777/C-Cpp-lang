#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;

    string query;
    cout << "Vvedite stroku"s << endl;
    getline(cin, query);

    string word;

    // замена for на range-based.
    for (char c : query)
    {
        if ((c != ' ') && (c != '\0'))
        {
            word.push_back(c);
        }
        else if (c == ' ')
        {
            words.push_back(word);
            word = ""s;
        }
        else if (c == '\0')
        {
            words.push_back(word);
            for (string wor : words)
            {
                cout << '[' << wor << ']' << endl;
            }
        }
        else
        {
            cout << "--------------------------"s << endl;
        }
    }
    return 0;
}