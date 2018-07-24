#include <stdio.h>
#include <cs50.h>
#include <math.h>


int get_length(long number);
int check_initial_digits(long number, int digits, int length, int diglen);
int check_luhn(long number, int length);

int main(void)
{
    //Credit card checker.

#define AMEX "AMEX\n"
#define INVALID "INVALID\n"
#define VISA "VISA\n"
#define MASTERCARD "MASTERCARD\n"

    string validity;
    //Get input number
    long number = get_long_long("Number: ");

    //Get Length
    int length = get_length(number);

    //Check against allowed lengths and starting combinations
    switch (length)
    {
        case 13:
            //VISA Numbers with 13 digits begin with 4
            if (check_initial_digits(number, 4, length, 1))
            {
                validity = VISA;
            }
            else
            {
                validity = INVALID;
                goto exit;
            }
            break;
        case 15:
            //AMEX numbers with 15 digits begin with 34 or 37
            if ((check_initial_digits(number, 34, length, 2)) ||
                (check_initial_digits(number, 37, length, 2)))
            {
                validity = AMEX;
            }
            else
            {
                validity = INVALID;
                goto exit;
            }
            break;
        case 16:
            if (check_initial_digits(number, 4, length, 1))
            {
                //VISA Numbers with 16 digits begin with 4
                validity = VISA;
            }
            else if ((check_initial_digits(number, 51, length, 2)) ||
                     (check_initial_digits(number, 52, length, 2)) ||
                     (check_initial_digits(number, 53, length, 2)) ||
                     (check_initial_digits(number, 54, length, 2)) ||
                     (check_initial_digits(number, 55, length, 2)))
            {
                //Mastercard numbers with 16 Digits begin with 51/52/53/54/55
                validity = MASTERCARD;
            }
            else
            {
                validity = INVALID;
                goto exit;
            }
            break;
        default:
            validity = INVALID;
            goto exit;
            break;
    }

    if (!(check_luhn(number, length)))
    {
        validity = INVALID;
    }

exit:
    printf("%s", validity);
}

int get_length(long number)
{
    // Gets Length of an integer
    int l = !number;
    while (number)
    {
        l++;
        number /= 10;

    }
    return l;
}

int check_initial_digits(long number, int digits, int length, int diglen)
{
    //Checks if the first (length digits) digits of a number equal a particular value.
    //Get first (diglen) digits of a number
    int real_digits = number / pow(10, (length - diglen));
    //Check these digits
    if (digits == real_digits)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_luhn(long number, int length)
{
    // Checks a number against luhns algorithm
    int single_sum = 0;
    int double_sum = 0;
    int position = 1;
    int digit;
    int doubledigit;
    while (position <= length)
    {
        //Gets induvidual digits, starting from the end of the number
        int digit = number % 10;
        if (position % 2)
        {
            single_sum += digit;
        }
        else
        {
            doubledigit = (digit * 2);
            while (doubledigit)
            {
                double_sum += (doubledigit % 10);
                doubledigit /= 10;
            }
        }
        number /= 10;
        position ++;
    }
    int total_sum = single_sum + double_sum;
    if (total_sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
