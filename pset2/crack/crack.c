#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <crypt.h>
#include <string.h>
#include <stdlib.h>

void fill_options(string input);


int main(int argc, string argv[])
{
#define SETLENGTH 52
    string hash;
    if (argc == 2)
    {
        //Get Hash from argument
        hash = argv[1];
    }
    else
    {
        printf("Usage: ./crack hash");
        return 1;
    }

    //Get salt from hash
    char salt[3];
    strncpy(salt, hash, 2);
    salt[2] = '\0';

    //Set up characters to try
    char options[SETLENGTH];

    fill_options(&options);
    //Try all single character combinations
    char attempt[6];
    attempt[5] = '\0';
    for (int pos5 = 0; pos5 < SETLENGTH; pos5++)
    {
        attempt[4] = options[pos5];
        for (int pos4 = 0; pos4 < SETLENGTH; pos4++)
        {
            attempt[3] = options[pos4];
            for (int pos3 = 0; pos3 < SETLENGTH; pos3++)
            {
                attempt[2] = options[pos3];
                for (int pos2 = 0; pos2 < SETLENGTH; pos2++)
                {
                    attempt[1] = (options)[pos2];
                    for (int pos1 = 0; pos1 < SETLENGTH; pos1++)
                    {
                        attempt[0] = (options)[pos1];
                        //printf(" attempt is %s, hash is %s \n", attempt, crypt(attempt,salt));
                        if (strcmp(crypt(attempt, salt), hash) == 0)
                        {
                            printf("%s\n", attempt);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("failed");

}
void fill_options(string options)
{
    int i;
    //fill in first with null character
    options[0] = '\0';
    //fill in lower case letters
    for (i = 0; i < 26; i++)
    {
        options[1 + i] = 'a' + i;
    }
    //fill in upper case letters
    for (i = 0; i < 26; i++)
    {
        options[27 + i] = 'A' + i;
    }
}
