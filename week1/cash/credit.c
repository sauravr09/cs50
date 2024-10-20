#include <cs50.h>
#include <stdio.h>

long get_card(void);
void check_sum(long number);

int main(void)
{
    long number = get_card();
    check_sum(number);
}

long get_card(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);
    return card_number;
}

void check_sum(long number)
{
    long total = 0;
    int counter = 0;
    int split_product; // use to handle if the product is not a single digit
    int first_digit;
    int first_two_digit;
    while (number > 0)
    {
        // check for odd; find last digit and multiply by 2 and add to total.
        if ((counter % 2) != 0)
        {
            split_product = (number % 10) * 2;
            if (split_product > 9) // if not a single digit
            {
                while (split_product > 0)
                {
                    total += (split_product % 10);
                    split_product = (split_product / 10);
                }
            }
            else
            {
                total += (number % 10) * 2;
            }
        }
        // if not odd, it must be even
        else
        {
            total += (number % 10);
        }
        if ((number < 100) && (number >= 10)) // find the first 2 digit
        {
            first_two_digit = number;
        }
        if (number < 10) // check if the next iteration of number is the first digit.
        {
            first_digit = number;
        }
        number = (number / 10);
        counter++;
    }

    string result;
    if ((total % 10) == 0)
    {
        switch (first_digit)
        {
            case 3:
                if ((counter == 15) && ((first_two_digit == 37) || (first_two_digit == 34)))
                {
                    result = "AMEX\n";
                }
                else
                {
                    result = "INVALID\n";
                }
                break;
            case 4:
                if (counter == 13 || counter == 16)
                {
                    result = "VISA\n";
                }
                else
                {
                    result = "INVALID\n";
                }
                break;
            case 5:
                if ((counter == 16) && ((first_two_digit <= 55) && (first_two_digit >= 51)))
                {
                    result = "MASTERCARD\n";
                }
                else
                {
                    result = "INVALID\n";
                }
                break;
        }
    }
    else
    {
        result = "INVALID\n";
    }

    printf("%s", result);
}