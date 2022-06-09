// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy the header to the new file
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t),  HEADER_SIZE, output);

    // Copy the changed values to the new file
    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}

while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // If the block has the jpeg demarcator at start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] > 223) && (buffer[3] < 239))
        {
            start = 1;
            sprintf(name, "%03d.jpg", counter);

            FILE *new_output = fopen(name, "w");
            if (new_output == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }

            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, new_output);
            counter++;

            fclose(new_output);
        }
        else
        {
            if (start)
            {
                FILE *append_output = fopen(name, "a");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, append_output);
                fclose(append_output);
            }
        }
    }