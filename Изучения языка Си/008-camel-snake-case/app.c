#include <stdio.h>
#include <stdlib.h>

/**
 * Upper Camel Case - Console.WriteLine() <- C#, Java
 * Lower Camel Case - writeLine() <- JS, PHP
 * Snake Case - write_line() <- C
 */
int func_two();
int func_one();

int main() {
    //instructions
    func_one();
    return 0;
}

int func_one(){
    //instructions
    return func_two();
}

int func_two(){
    //instructions
    return 0;
}