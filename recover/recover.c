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
        printf("Usage: ./recover input\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int start = 0;
    int counter = -1;

    FILE *output;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // If the block has the jpeg demarcator at start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            start = 1;
            counter++;
            output = fopen("name", "w");
            if (output == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }
        }

        if (start)
        {
            // Create new output, and write to it
            start = 0;
        }
        else
        {
            // Continue writing to the initial file
        }
    }
}