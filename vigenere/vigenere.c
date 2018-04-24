// first version of vigenere combined with caesar, compiles but not combined yet
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    string key = argv[1];
    printf("%s\n", key);

    int i;
    int j;
    if (argc != 2)
        // error message for non alpha command line entry
    {
        printf("Please enter ./vigenere and alphabetic key string Usage: strings \"phrases\"\n");
        return 1;
    }
    else
    {
        int keylength = strlen(key);

        for (i = 0; i < keylength; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Please enter an alphabetic key string\n");
                return 1;
            }
        }

        // prompt for a the plaintext variable to encrypt
        string s = get_string("plaintext: ");
        printf("ciphertext: ");

        int changeval;

        // for loop converts plaintextascii to numeric value
        for (i = 0, j = 0; i < strlen(s); i++)
        {
            // increment step through the key
            int keycount = key[j % keylength];
            if (isupper(keycount))
            {
                changeval = keycount - 'A';
            }
            else if (islower(keycount))
            {
                changeval = keycount - 'a';
            }

            //add isalpha check here
            if (isalpha(s[i]))
            {
                if (isupper(s[i]))
                {
                    // do upper case math
                    int upper = ((((s[i]) - 'A' + changeval) % 26) + 'A');
                    j++;
                    printf("%c", upper);
                }
                else if (islower(s[i]))
                {
                    // do lower case math
                    int lower = ((((s[i]) - 'a' + changeval) % 26) + 'a');
                    j++;
                    printf("%c", lower);
                }

            }
            else if (!isalpha(s[i]))
            {
                // pass the value through
                printf("%c", s[i]);
            }
        }
        printf("\n");
        return 0;
    }
}



