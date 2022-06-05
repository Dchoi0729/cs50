#include <cs50.h>
#include <stdio.h>

void hi(int hi[]);

int main(void)
{
    int b[2];
    //hi(b);

    for (int i = 0; i < 2; i++)
    {
        printf("%i\n", b[i]);
    }


}

void hi(int a[])
{
    a[0] = 123;
}