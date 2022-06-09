#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(void)
{
    BYTE t = 255;
    if (t == 0xff)
    {
        printf("success\n");
    }
    else
    {
        printf(":(\n");
    }
}