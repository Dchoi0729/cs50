#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int a[3];
    int *b = malloc(3*sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        a[i] = i;

        *(b+i) = i;
    }

    printf("a: %i %i %i", a[0], a[1], a[2]);
    printf("b: %i %i %i", *b, *(b+1), *(b+2));

}