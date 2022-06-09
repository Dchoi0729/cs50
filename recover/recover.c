#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

// Block size
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int counter = 0;
    int start = 0;
    char name[8];

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // If the block has the jpeg demarcator at start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] > 223) && (buffer[3] < 239))
        {
            // The first jpeg file is found
            start = 1;

            // Create new output file with correct name
            sprintf(name, "%03d.jpg", counter);
            FILE *new_output = fopen(name, "w");
            if (new_output == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }

            // Write content to new file
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, new_output);
            counter++;

            fclose(new_output);
        }
        else
        {
            // Once the first photo has been found, and the block isn't a starting block
            if (start)
            {
                // Append content to existing file
                FILE *append_output = fopen(name, "a");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, append_output);
                fclose(append_output);
            }
        }
    }

    // Close input file
    fclose(raw_file);

    return 0;
}