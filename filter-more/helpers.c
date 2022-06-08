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
            image[r][c].rgbtRed = average_value;
            image[r][c].rgbtGreen = average_value;
            image[r][c].rgbtBlue = average_value;
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
            image[r][c] = image[r][width - c - 1];
            image[r][width - c - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];

    // Fill the temp 2d array with the blurred RGB values
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            // Use uint16_t since BYTE can't hold the sum of (maximum) 9 RGB values
            uint16_t red_sum = 0, green_sum = 0, blue_sum = 0;
            double counter = 0.0;

            // For surrounding pixels
            for (int i = r - 1; i < r + 2; i++)
            {
                for (int j = c - 1; j < c + 2; j++)
                {
                    if ((i > -1) && (i < height) && (j > -1) && (j < width))
                    {
                        RGBTRIPLE surrounding_pixel = image[i][j];
                        red_sum += (uint16_t) surrounding_pixel.rgbtRed;
                        green_sum += (uint16_t) surrounding_pixel.rgbtGreen;
                        blue_sum += (uint16_t) surrounding_pixel.rgbtBlue;
                        counter++;
                    }
                }
            }

            temp[r][c].rgbtRed = (BYTE) round(red_sum / counter);
            temp[r][c].rgbtGreen = (BYTE)round(green_sum / counter);
            temp[r][c].rgbtBlue = (BYTE) round(blue_sum / counter);
        }
    }

    // Fill in the original image 2d aray with values
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            image[r][c] = temp[r][c];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
