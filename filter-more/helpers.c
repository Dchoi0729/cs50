#include "helpers.h"
#inlucde <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterating through all pixel of image
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            RGBTRIPLE pixel = image[r][c];

            // Replace each pixel by the average of the three blue
            BYTE average_value = (pixel.rgbtBlue + pixel.rgbtBlue + pixel.rgbtBlue) / 3;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
