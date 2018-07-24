#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get height (between 0 and 23) from user input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);


    for (int line = 1; line <= height; line++)
    {
        int boxes = line;
        int spaces = height - line;

        int i; //loop variable
        for (i = 1; i <= spaces; i++)
        {
            printf(" ");
        }
        for (i = 1; i <= boxes; i++)
        {
            printf("#");
        }
        printf("  ");
        for (i = 1; i <= boxes; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}