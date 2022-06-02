// Checks if credit card number is valid

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int get_digit(int place);
    bool check_sum(long number);

    // Get user input
    long number = get_long("Number: ");

    if(check_sum(number))
    {

    }
    else
    {
        printf("INVALID\n");
    }
}