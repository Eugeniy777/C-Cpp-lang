#include <stdio.h>
#include <stdlib.h>

int func_three();
int func_two();
int func_one();

int main() {
    puts("Pognali: ");
    func_one();
    return 0;
}

int func_one(){
    puts("func_one");
    return func_two();
}

int func_two(){
    puts("func_two");
    return func_three();
}

int func_three()
{
    puts("func_three");
    return 0;
}