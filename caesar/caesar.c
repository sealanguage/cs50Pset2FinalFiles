#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
//  arg c has 2 values ./ceasar and the key
{

    // this block demands 2 command line arguments and returns a request for 2 arguments
    if (argc != 2)
    {
        printf("Please use 2 command-line arguments\n");
        return 1;
    }


    int key = atoi(argv[1]);    // declare k as an int as per directions, convert glyph to number
    int lower;

    // prompt for a the plaintext variable to encrypt
    string s = get_string("plaintext: ");
    printf("ciphertext: ");

    // for loop converts ascii to numeric value
    for (int i = 0; i < strlen(s); i++)
    {
        // add isalpha check here
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                // do upper case math
                int upper = (((int) s[i] - 65) + key);
                upper = (upper % 26) + 65;
                // printf("got conversion upper %i %c\n", upper, upper);
                printf("%c", upper);

            }
            else
            {
                // do lower case math
                lower = (((int) s[i] - 97) + key);
                lower = (lower % 26) + 97;
                printf("%c", lower);
            }
        }
        else
        {
            printf("%c", s[i]);
        }
    }

    printf("\n");
    return 0;
}


