#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    /*
    Slozhnost' O(n)
    */
    srand(time(NULL));
    cout << "Enter key: " << endl;
    int key = 0;
    cin >> key;
    cout << "Enter size of array: " << endl;
    int size = 0;
    cin >> size;
    // sozdanie dinam massiv
    int *arr = new int[size];
    // initialization dinam massiv
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % key + 1;
        cout << arr[i] << ' ';
        if (arr[i] == key)
        {
            cout << "\nYou found a key! Is's \"" << key << "\"" << endl;
        }
    }
    cout << "You can't found a key!" << endl;
    delete[] arr;
    return 0;
}