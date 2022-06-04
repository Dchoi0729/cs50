#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    printf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
}

// Returns the number of words in the text
int count_words(string text)
{
    int sum = 1;

    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            sum++;
        }
    }
    return sum;
}

// Returns the number of letters in the text
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