#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool contains_dup(string word);

int main(void)
{
    if (contains_dup("heeoo"))
    {
        printf("true");
    }
    else
    {
        printf("fail");
    }
}

// Checks if word contains duplicates
bool contains_dup(string word)
{
    // For each alphabet
    for (int i = 65; i < 91; i++)
    {
        int sum = 0;

        for (int j = 0, n = strlen(word); j < n; j++)
        {
            if (toupper(word[j]) == i)
            {
                sum++;
            }
        }


        if (sum > 1)
        {
            return true;
        }
    }

    return false;
}