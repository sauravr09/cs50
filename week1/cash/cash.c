#include <cs50.h>
#include <stdio.h>

int get_change(void);
int get_coins(int change);

int main(void)
{
    int change = get_change();
    int coins = get_coins(change);

    printf("%i\n", coins);
}

// get change from the user
int get_change(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    return change;
}
// find the least coin amount
int get_coins(int change)
{
    int coin_count = 0;

    while (change > 0)
    {
        // check for quarters
        if (change / 25 >= 1)
        {
            change -= 25;
            coin_count++;
        }
        // check for dime
        else if (change / 10 >= 1)
        {
            change -= 10;
            coin_count++;
        }
        // check for nickel
        else if (change / 5 >= 1)
        {
            change -= 5;
            coin_count++;
        }
        // check for penny
        else
        {
            change -= 1;
            coin_count++;
        }
    }
    return coin_count;
}