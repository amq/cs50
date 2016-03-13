#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void ciphertext(string plaintext, int key);

int main(int argc, char *argv[])
{
    string plaintext;
    int key;

    /* sanity check */
    if (argc != 2)
    {
        printf("Usage:\n");
        printf("./caesar <numeric key>\n");
        return 1;
    }
    
    /* user input */
    key = atoi(argv[1]);
    plaintext = GetString();
    
    /* output */
    ciphertext(plaintext, key);

    return 0;
}

void ciphertext(string plaintext, int key)
{
    int length = strlen(plaintext);
    int i;
    
    for (i = 0; i < length; i++)
    {
        if ( isalpha(plaintext[i]) )
        {
            if ( islower(plaintext[i]) )
            {
                printf("%c", 'a' + (plaintext[i] + key - 'a') % 26);
            }
            if ( isupper(plaintext[i]) )
            {
                printf("%c", 'A' + (plaintext[i] + key - 'A') % 26);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
