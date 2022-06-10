#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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