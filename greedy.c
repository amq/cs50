/*
O hai! How much change is owed?
4.2
18
*/

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // initialize the variables with zeroes
    // since they are not global/static and contain garbage values
    float input = 0;
    int cents = 0;
    int coins = 0;

    // array of available coin types
    int cointypes[] = {25, 10, 5, 1};

    do
    {
        printf("O hai! How much change is owed?\n");
        input = GetFloat();
    }
    while (input < 0);

    // input of 4.2 would result in 419.999 without rounding
    cents = round(input * 100);

    // assumes you have '1' in cointypes[]
    // additional checks would be required otherwise
    for (int i = 0; cents > 0; i++)
    {
        coins = coins + cents / cointypes[i];
        cents = cents % cointypes[i];
    }

    printf("%d\n", coins);
}
