#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    struct Human {
        int age;
        float weight;
        float height;
    } Anton, Leonid, Fedor, Basilio;
    Anton.age = 17;
    Leonid.weight = 105.3;
    Fedor.height = 185.1;
    
    struct Human Putin = {70, 95.0, 150.3};
    return 0;
}