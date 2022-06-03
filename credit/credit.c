// Checks if credit card number is valid

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int get_digit(long number, int place);
    int get_number_length(long number);
    bool check_sum(long number);

    // Get user input
    long number;
    do
    {
        number = get_long("Number: ");
    } while(number < 0);


    printf("%li\n", number);
}

int get_number_length(long number)
{

}

int get_digit(long number, int place)
{
    return(number / 10**)
}