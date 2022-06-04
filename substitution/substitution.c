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

    // Creates an all uppercase version of key
    char upperKey[26];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        upperKey[i] = toupper(key[i]);
    }

    // Get user's plaintext
    string plaintext = get_string("plaintext:  ");

    // Begin printing ciphertext line
    printf("ciphertext: ");

    // Print the individual character's mapped to encrypted version
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int index = toupper(plaintext[i]) - 65;

            if (isupper(plaintext[i]))
            {
                printf("%c", upperKey[index]);
            }
            else
            {
                printf("%c", tolower(upperKey[index]));
            }

        }
        else
        {
            printf("%c", plaintext[i]);
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
