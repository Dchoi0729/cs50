#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_alpha(string word);

int main(int argc, string argv[])
{
    // string key = argv[1];

    // Checks if one command-line argument has been provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Checks if a valid string of 26 alphabets has been provided
    if (strlen(argv[1]) != 26 || !only_alpha(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
}

// Work on this
bool only_alpha(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]) == 0)
        {
            return false;
        }
    }

    return true;
}
