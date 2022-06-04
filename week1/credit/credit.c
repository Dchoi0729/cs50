// Checks if credit card number is valid

#include <cs50.h>
#include <stdio.h>

long power(int base, int power);
int get_digit(long number, int place);
int get_number_length(long number);
bool check_sum(long number);

int main(void)
{
    // Get user input
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    int numberLength = get_number_length(number);
    string answer = "INVALID";

    //  If valid card
    if (check_sum(number))
    {
        int firstTwo = 10 * get_digit(number, numberLength - 1) + get_digit(number, numberLength - 2);

        // Check for American Express card
        if (numberLength == 15 && (firstTwo == 34 || firstTwo == 37))
        {
            answer = "AMEX";
        }

        // Check for Master Card
        if (numberLength == 16 && (firstTwo > 50 && firstTwo < 56))
        {
            answer = "MASTERCARD";
        }

        // Check for Visa Card
        if ((numberLength == 13 || numberLength == 16) && (firstTwo / 10 == 4))
        {
            answer = "VISA";
        }

    }

    printf("%s\n", answer);
}

// Implements Luhn's algorithm and returns true/false
bool check_sum(long number)
{
    int numberLength = get_number_length(number);
    int sum = 0;

    // For every other digit starting from second to last
    for (int i = 1; i < numberLength; i = i + 2)
    {
        int n = get_digit(number, i) * 2;
        if (n > 9)
        {
            sum = sum + (n / 10) + (n % 10);
        }
        else
        {
            sum = sum + n;
        }
    }

    // Adds the rest of the numbers
    for (int i = 0; i < numberLength; i = i + 2)
    {
        sum = sum + get_digit(number, i);
    }


    return (sum % 10 == 0);
}

// Returns length of given number
int get_number_length(long number)
{
    int length = 0;

    while (true)
    {
        if (number / power(10, length) > 0)
        {
            length++;
        }
        else
        {
            break;
        }
    }

    return (length);
}

// Returns the given place of given number (starting with 0)
int get_digit(long number, int place)
{
    return ((number / power(10, place)) % 10);
}

// Returns base^power
long power(int base, int power)
{
    long answer = 1;
    for (int i = 0; i < power; i++)
    {
        answer = answer * base;
    }

    return answer;
}