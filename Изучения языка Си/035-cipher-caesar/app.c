#include <stdio.h>

#define ENCRYPTED_MESSAGE "SVVRZSPRLFVBOHJRLKTL"
#define ALPHABET_SIZE 26
#define CIPHER_KEY 7
#define ENDL ""

int main()
{
    char alphabet_encrypted[ALPHABET_SIZE] = {'\0'};    // encripted alphabet
    char alphabet[ALPHABET_SIZE] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'};           // original alphabet
    // vyvod original alphabet
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        printf("[%c] ", alphabet[i]);
    }
    puts(ENDL);

    // zapolnyaem i vyvodim encrypted alphabet massiv
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        int offset = (i + CIPHER_KEY) % ALPHABET_SIZE; // smeschenie
        alphabet_encrypted[i] = alphabet[offset];
        printf("[%c] ", alphabet_encrypted[i]);
    }
    puts(ENDL);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < ALPHABET_SIZE; j++)
        {
            if (ENCRYPTED_MESSAGE[i] == alphabet_encrypted[j])
            {
                // avtomaticheski podstavlyaem original vmesto encrypted
                printf("%c ", alphabet[j]);
            }
        }
    }
    return 0;
}