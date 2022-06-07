#include <stdio.h>

int main() {
    int array[23][42];
    printf("size of array:   %zu\n", sizeof(  array)/sizeof(int));
    printf("size of row:     %zu\n", sizeof( *array)/sizeof(int));
    printf("size of element: %zu\n", sizeof(**array)/sizeof(int));
    return 0;
}

//https://overiq.com/c-programming-101/pointers-and-2-d-arrays/