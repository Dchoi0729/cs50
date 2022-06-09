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
    int counter = 0;
    char name[8];

    FILE *new_output, *append_output;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // If the block has the jpeg demarcator at start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            sprintf(name, "%03d.jpg", counter);
            printf("%03d.jpg\n", counter);

            new_output = fopen(name, "w");
            if (new_output == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }

            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, new_output);
            counter++;
        }
        else
        {
            append_output = fopen(name, "a");
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, append_output);
        }
    }
}