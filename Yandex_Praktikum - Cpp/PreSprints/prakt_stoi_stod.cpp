#include <iostream>
#include <string>

using namespace std;

int main(){
    int numb = 750;
    double dub = 786.458;
    string pustoi_int, pustoi_double, numb_str = "Hello78597445";
    pustoi_int = to_string(numb);
    pustoi_double = to_string(dub);
    cout << pustoi_int << ' ' << pustoi_double << endl;
    int zet = (stoi(numb_str));
    double zed = (stod(numb_str));
    cout << zet << ' ' << zed << endl;
    return 0;
}