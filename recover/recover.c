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

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {


    }

    // Creating files - should edit
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

}