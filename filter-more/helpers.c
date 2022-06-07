#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterating through all pixel of image
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            RGBTRIPLE pixel = image[r][c];
            BYTE average_value = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);

            // Replace each pixel by the average of the three blue
            image[r][c].rgbtBlue = average_value;
            image[r][c].rgbtGreen = average_value;
            image[r][c].rgbtRed = average_value;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterating through the left side of the image
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width / 2; c++)
        {
            RGBTRIPLE temp = image[r][c];
            image[r][c] = image[r][width -c];
            image[r][width-c] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            BYTE red_val, green_val, blue_val;
            RGBTRIPLE pixel = image[r][c];

            // For surrounding pixels
            for (int i = r - 1; i < r + 2; i++)
            {
                for (int j = c - 1; j < c + 2; j++)
                {
                    RGBTRIPLE surrounding_pixel = image[i][j];
                    red_val =+ surrounding_pixel.rgbtRed;
                    green_val =+ surrounding_pixel.rgbtGreen;
                    blue_val =+ surrounding_pixel.rgbtBlue;
                }
            }
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
