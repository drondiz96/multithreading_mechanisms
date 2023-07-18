#include "usefullfunc.h"
int* summ;
int count = 0;



int unic(int* arr, size_t len)
{
    for (int count = len - 1; count > 1; count--)
    {
        if (arr[count] > arr[count - 1])
            return 0;
    }
    return 1;
}


void num_as_summ(int i, int num, int sum)
{
    if (num < 0)
        return;
    summ[i] = num;
    if (num <= 1 && unic(summ, i))
    {
        //print_array(summ, i + 1);
        count++;
        return;
    }
    while (summ[i] > 0 && unic(summ, i))
    {
        num_as_summ(i + 1, num - summ[i], sum + summ[i]);
        summ[i]--;
    }
}

void calculations(void)
{
    int num = 5;
    summ = (int*)calloc(num + 1, sizeof(int));
    if (summ == NULL)
        return;
    summ[0] = num + 1;
    time_t t = clock();
    num_as_summ(1, num, 0);
    printf("%d time: %lld", count, clock() - t);
}