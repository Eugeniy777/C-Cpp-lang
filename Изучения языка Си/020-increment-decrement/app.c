#include <stdio.h>

int main()
{
    int local = 0;

    // local = local + 1;
    // local +=1;
    // ++local;

    // Prefix incrementation
    printf("++local: %i\n", ++local);
    printf("++local: %i\n", ++local);
    printf("++local: %i\n", ++local);

    // Prefix decrementation
    printf("--local: %i\n", --local);
    printf("--local: %i\n", --local);
    printf("--local: %i\n", --local);

    puts("POSTFIX");
    // Postfix incrementation
    printf("local++: %i\n", local++);
    printf("local++: %i\n", local++);
    printf("local++: %i\n", local++);

    // Postfix decrementation
    printf("local--: %i\n", local--);
    printf("local--: %i\n", local--);
    printf("local--: %i\n", local--);
    return 0;
}