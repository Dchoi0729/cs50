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
    FILE *output = NULL;
    char name[8];

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // If the block has the jpeg demarcator at start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] > 223) && (buffer[3] < 239))
        {
            if (output != NULL)
            {
                fclose(output);
            }

            // Create new output file with correct name
            sprintf(name, "%03d.jpg", counter);
            output = fopen(name, "w");
            if (output == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }

            counter++;
        }

        if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
        }
    }

    // Close input and output (the last jpeg) file
    fclose(raw_file);
    fclose(output);

    return 0;
}