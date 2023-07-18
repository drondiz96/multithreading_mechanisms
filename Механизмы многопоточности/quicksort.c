#include "usefullfunc.h"
#define N 20

void qsort(int arr[N], int left, int right) 
{

    if (left >= right)
        return;
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    qsort(arr, left, j);
    qsort(arr, i, right);
}


int quicksort(void)
{
    int arr[N];
    for (size_t i = 0; i < N; i++)
        arr[i] = rand() % 10;

    print_array(arr, N);
    qsort(arr, 0, N - 1);
    print_array(arr, N);
    return 0;
}