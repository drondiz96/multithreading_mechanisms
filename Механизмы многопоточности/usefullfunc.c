#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_array(int* arr, size_t len)
{
    for (size_t i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void cpy_arry(int* source, int* dest, size_t len)
{
    for (size_t i = 0; i < len; i++)
        dest[i] = source[i];
}