#include <iostream>
using namespace std;

int main()
{
    //Считайте из стандартного ввода пять слов и выведите первые символы
    //введённых строк слитно. Под словом понимается последовательность символов,
    //таких как буквы, цифры, знаки препинания. Слова разделяются одним пробелом.

    string onee, twoo, threee, fourr, fivee;
    printf("Vvedite 5 slov:\n");
    cin >> onee >> twoo >> threee >> fourr >> fivee;
    cout << onee[0] << twoo[0] << threee[0] << fourr[0] << fivee[0] << endl;
    return 0;
}