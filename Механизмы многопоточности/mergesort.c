#include "usefullfunc.h"
#define N 20

void msort(int* arr, int* buffer, int left, int right)
{
    if (right - left == 0)
    {
        buffer[left] = arr[left];
        return;
    }
    memcpy(buffer, arr, (right - left + 1) * sizeof(int));
    msort(buffer, arr, left, (right + left) / 2);
    msort(buffer, arr, (right + left) / 2 + 1, right);
    int i = left;
    int j = (right + left) / 2 + 1;
    int count = left;
    while (i <= (right + left) / 2 && j <= right)
        if (buffer[i] < buffer[j])
            arr[count++] = buffer[i++];
        else
            arr[count++] = buffer[j++];

    while (i <= (right + left) / 2)
        arr[count++] = buffer[i++];
    while (j <= right)
        arr[count++] = buffer[j++];
}

int mergesort(void)
{
    int arr[N];
    for (size_t i = 0; i < N; i++)
        arr[i] = rand() % 10;

    int buffer[N];
    memcpy(buffer, arr, N * sizeof(int));
    print_array(arr, N);
    msort(arr, buffer, 0, N - 1);
    print_array(arr, N);
    return 0;
}