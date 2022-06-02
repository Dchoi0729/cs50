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
    while(height > 8 || height < 1);

    // Print pyramid with given height
    for(int r = 0; r < height; r++)
    {
        for(int c = 0; c < 2*height+2; c++)
        {

        }
    }
}