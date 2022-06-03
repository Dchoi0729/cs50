// Checks if credit card number is valid

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int get_digit(long number, int place);
    bool check_sum(long number);

    // Get user input
    long number;
    do
    {
        number = get_long("Number: ");
    } while(number < 0);


    printf("%li\n", number);
}