#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void ciphertext(string plaintext, string key);
int mod(int a, int b);

int main(int argc, char *argv[])
{
    string plaintext;
    string key;
    int length;
    int i;

    /* sanity check */
    if (argc != 2)
    {
        printf("Usage:\n");
        printf("./devigenere <alphabetic key>\n");
        return 1;
    }
    
    key = argv[1];
    length = strlen(key);

    for (i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage:\n");
            printf("./devigenere <alphabetic key>\n");
            return 1;
        }
    }

    /* user input */
    plaintext = GetString();
    
    /* output */
    ciphertext(plaintext, key);

    return 0;
}

void ciphertext(string plaintext, string key)
{
    int length = strlen(plaintext);
    int key_length = strlen(key);
    int offset;
    int i, j;
    
    for (i = 0, j = 0; i < length; i++)
    {
        if ( isalpha(plaintext[i]) )
        {
            offset = mod((toupper(plaintext[i]) - 'A' - toupper(key[j % key_length]) - 'A'), 26);

            if ( islower(plaintext[i]) )
            {
                printf("%c", 'a' + offset);
            }
            if ( isupper(plaintext[i]) )
            {
                printf("%c", 'A' + offset);
            }
            
            j++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}
