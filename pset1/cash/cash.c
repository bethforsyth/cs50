#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get Change Value
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    //Convert to cents
    int cents = round(change * 100);

    int coins [4] = {25, 10, 5, 1};

    int numcoins = 0;
    int cointype;

    for (cointype = 0; cointype < 4; cointype ++)
    {
        //printf("Coin is %d\n", coins[cointype]);
        while (cents - coins[cointype] >= 0)
        {
            //printf("Value left is %d\n", cents);
            //printf("coins so far: %d\n", numcoins);
            cents -= coins[cointype];
            numcoins++;
        }
    }

    printf("%d\n", numcoins);
}
