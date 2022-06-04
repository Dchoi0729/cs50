#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_alpha(string word);

int main(int argc, string argv[])
{
    // Checks if one command-line argument has been provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Checks if a valid string of 26 alphabets has been provided
    if (strlen(key) != 26 || !only_alpha(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    printf("ciphertext: ");

    string plaintext = get_string("plaintext: ");

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {

        }
        else
        {
            printf("%c", word[i]);
        }
    }

    printf("\n");

    return 0;
}

// Checks if word only contains alphabets
bool only_alpha(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (!isalpha(word[i]))
        {
            return false;
        }
    }

    return true;
}
