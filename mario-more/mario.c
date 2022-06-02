// Recreates the pyramids from Mario for a given height

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Get user input(must be an int between 1-8)
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    // For each row, r
    for (int r = 0; r < height; r++)
    {
        // Print spaces
        for (int i = 0 ; i < height - r - 1; i++)
        {
            printf(" ");
        }

        // Print left hashes
        for (int i = 0 ; i < r + 1; i++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print right hashes
        for (int i = 0 ; i < r + 1; i++)
        {
            printf("#");
        }

        // Next row
        printf("\n");
    }
}