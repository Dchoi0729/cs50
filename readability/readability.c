#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    printf("%i letters\n", count_letters(text));
}

int count_letters(string text)
{
    int sum = 0;

    // Iterating through each character of text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            sum++;
        }
    }

    return sum;
}