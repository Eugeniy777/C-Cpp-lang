#include <iostream>
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
*/
using namespace std;

void foo(char *str);

int main(){
    char *str_arr[] = { "Hello", "world", "Test"};
    for (int i = 0; i < 3; i++)
    {
        cout << str_arr[i] << endl;
    }
    
    //foo(str_arr);
    return 0;
}

/*
void foo(char *str){
    printf("%s", str);
}
*/