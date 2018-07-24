#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int check_string(string mystring);

int main(int argc, string argv[])
{
    //implements vignere cipher (with cl codeword on user input)
    string codeword;
    int codelength;
    //Get codeword- should be single word (no non-letter characters)
    if (argc == 2 && check_string(argv[1]))
    {
        codeword = argv[1];
        codelength = strlen(codeword);
        printf("codeword is %s\n", codeword);
    }
    else
    {
        //print error and return if invalid codeword
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    //Get input string
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);

    int codepos = 0;

    printf("ciphertext: ");
    for (int i = 0 ; i < length ; i++)
    {
        //for each letter
        if (isalpha(plaintext[i]))
        {
            //shift by relevant letter in codeword (a=0, b=1 etc)
            int codeshift = tolower(codeword[codepos]) - 'a';
            char newchar = plaintext[i] + codeshift;
            //if shifted off the end of the alphabet, loop round and start again (in same case)
            if ((tolower(plaintext[i]) - 'a') + codeshift >= 26)
            {
                newchar -= 26;
            }
            printf("%c", newchar);
            //Increment letter of codeword, looping round if we get the end of the word
            codepos = (codepos + 1) % codelength;
        }
        else
        {
            //print non-letter characters as is
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

int check_string(string mystring)
{
    //check if a string is entirely  letters
    int length = strlen(mystring);
    for (int i = 0 ; i < length ; i++)
    {
        if (!(isalpha(mystring[i])))
        {
            return 0;
        }
    }
    return 1;
}
