#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char phrase[] = "We automatically collect and store certain types of information about your use of Amazon Services, including information about your interaction with content and services available through Amazon Services. Like many websites, we use cookies and other unique identifiers, and we obtain certain types of information when your web browser or device accesses Amazon Services and other content served by or on behalf of Amazon on other websites. Click here to see examples of what we collect";
    int alpha, blank, punct;
    alpha = blank = punct = 0;
    for (int i = 0; i < (sizeof(phrase) / sizeof(phrase[0])); i++)
    {
        if (isalpha(phrase[i]))
            alpha++;
        if (isblank(phrase[i]))
            blank++;
        if (ispunct(phrase[i]))
            punct++;
    }
    printf("Phrase have %i symbols of alphabet\n%i probels\nand %i symbols of punctuation", alpha, blank, punct);

    /*
    int array[10];
    printf("%i\n", sizeof(array));
    struct human{
     char name;
     int age;
     double weight;
    };
    printf("%i, %i, %i, %i, %i, %i\n", sizeof(char), sizeof(int), sizeof(float), sizeof(double), sizeof(long double), sizeof(struct human));
     */

    return 0;
}