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

    number = number /100;

    printf("%li\n", number);

    printf("%i\n",get_digit(number, 2));
}

int get_number_length(long number)
{
    return 1;
}

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