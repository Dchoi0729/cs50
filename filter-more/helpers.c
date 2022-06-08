#include "helpers.h"
#include <math.h>

BYTE combine_gxgy(double gx, double gy);

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
    RGBTRIPLE temp[height][width];
    int gx_kernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy_kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            // Use double since BYTE can't hold the sum of 9 RGB values
            // Double convenient later for mathematical expressions
            double gx_red_sum = 0, gx_green_sum = 0, gx_blue_sum = 0;
            double gy_red_sum = 0, gy_green_sum = 0, gy_blue_sum = 0;

            for (int i = r - 1; i < r + 2; i++)
            {
                for (int j = c - 1; j < c + 2; j++)
                {
                    double red = 0.0, blue = 0.0, green = 0.0;

                    if ((i > -1) && (i < height) && (j > -1) && (j < width))
                    {
                        RGBTRIPLE surrounding_pixel = image[i][j];
                        red = (double) surrounding_pixel.rgbtRed;
                        blue = (double) surrounding_pixel.rgbtBlue;
                        green = (double) surrounding_pixel.rgbtGreen;
                    }

                    // For gx kernel
                    gx_red_sum += red * gx_kernel[i - (r - 1)][j - (c - 1)];
                    gx_green_sum += green * gx_kernel[i - (r - 1)][j - (c - 1)];
                    gx_blue_sum += blue * gx_kernel[i - (r - 1)][j - (c - 1)];

                    // For gy kernel
                    gy_red_sum += red * gy_kernel[i - (r - 1)][j - (c - 1)];
                    gy_green_sum += green * gy_kernel[i - (r - 1)][j - (c - 1)];
                    gy_blue_sum += blue * gy_kernel[i - (r - 1)][j - (c - 1)];
                }
            }

            // Input sqrt(gx^2 + gy^2) into each RGB value
            temp[r][c].rgbtRed = combine_gxgy(gx_red_sum, gy_red_sum);
            temp[r][c].rgbtGreen = combine_gxgy(gx_green_sum, gy_green_sum);
            temp[r][c].rgbtBlue = combine_gxgy(gx_blue_sum, gy_blue_sum);
        }
    }

    // Fill in the original image 2d aray with values
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            image[r][c]= temp[r][c];
        }
    }
}

RGBTRIPLE 

// Helper function that combines gx and gy values and caps it at 255
BYTE combine_gxgy(double gx, double gy)
{
    double temp = round(sqrt(pow(gx, 2.0) + pow(gy, 2.0)));

    if (temp > 255)
    {
        return 255;
    }
    else
    {
        return (BYTE) temp;
    }
}
