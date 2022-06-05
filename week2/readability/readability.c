#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int sentences = count_sentences(text);

    // To ensure int division doesn't happen
    double words = (double) count_words(text);

    double averageLetters = letters / words * 100;
    double averageSentences = sentences / words * 100;
    double index = 0.0588 * averageLetters - 0.296 * averageSentences - 15.8;

    int finalIndex = (int) round(index);

    if (finalIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (finalIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", finalIndex);
    }

}

// Returns the number of sentences in the text
int count_sentences(string text)
{
    int sum = 0;

    // Iterating through each character of text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];

        if (c == '.' || c == '!' || c == '?')
        {
            sum++;
        }
    }

    return sum;
}

// Returns the number of words in the text
int count_words(string text)
{
    int sum = 1;

    // Iterating through each character of text
    for (int i = 0, n = strlen(text); i < n; i++)
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