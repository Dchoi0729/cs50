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
    } while(number < 0);

    int numberLength = get_number_length(number);



}

// Implements Luhn's algorithm and returns true/false
bool check_sum(long number)
{
    int numberLength = get_number_length(number);
    
    for(int i = 1; i < )
}

// Returns length of given number
int get_number_length(long number)
{
    int length = 0;

    while (true)
    {
        if (number / power(10,length) > 0)
        {
            length++;
        }
        else
        {
            break;
        }
    }

    return(length);
}

// Returns the given place of given number
int get_digit(long number, int place)
{
    return((number / power(10, place - 1))%10);
}

// Returns base^power
long power(int base, int power)
{
    long answer = 1;
    for(int i = 0; i < power; i++)
    {
        answer = answer * base;
    }

    return answer;
}