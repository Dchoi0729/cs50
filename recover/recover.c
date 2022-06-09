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
        FILE *output;

        // If the block has the jpeg demarcator at start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] > 223) && (buffer[3] < 239))
        {
            // Starting from the second jpeg file
            if (start)
            {
                fclose(output);
            }

            sprintf(name, "%03d.jpg", counter);

            output = fopen(name, "w");
            if (output == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }

            counter++;

            // First jpeg found - "started"
            start = 1;
        }

        // If the first jpeg file was found
        if (start)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
        }

    }

    // Close input file
    fclose(raw_file);

    return 0;
}