#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void ciphertext(string plaintext, string key);

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
        printf("./vigenere <alphabetic key>\n");
        return 1;
    }
    
    key = argv[1];
    length = strlen(key);

    for (i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage:\n");
            printf("./vigenere <alphabetic key>\n");
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
    int i, j;
    
    for (i = 0, j = 0; i < length; i++)
    {
        if ( isalpha(plaintext[i]) )
        {
            if ( islower(plaintext[i]) )
            {
                printf("%c", 'a' + (plaintext[i] - 'a' + tolower(key[j % key_length]) - 'a') % 26);
            }
            if ( isupper(plaintext[i]) )
            {
                printf("%c", 'A' + (plaintext[i] - 'A' + toupper(key[j % key_length]) - 'A') % 26);
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
