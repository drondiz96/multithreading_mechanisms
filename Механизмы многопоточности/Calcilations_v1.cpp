#include <iostream>
#include <time.h>
using namespace std;
#define N 10000
size_t realIndex = 0, arr_size = 0;
size_t** arr;

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

void merge(size_t index)
{
	if (arr[index][0] == 1 || realIndex > N)// || arr[index][0] - 1 < arr[index + 1][0]
	{
		return;
	}
	else
	{
		for (size_t i = 1; i < arr_size && realIndex + 1 < N; i++)
		{
			realIndex++;
			memcpy(arr[realIndex], arr[index], arr_size * sizeof(size_t));
			arr[realIndex][0]--;
			arr[realIndex][i]++;

			bool flag = false;
			for (size_t j = 0; j < arr_size - 1; j++)
				if (compare(arr[realIndex] + j, arr[realIndex] + j + 1) < 0)
				{
					realIndex--;
					flag = true;
					break;
				}
			for (size_t j = 0; j < realIndex; j++)
				if (memcmp(arr[j], arr[realIndex], arr_size * sizeof(size_t)) == 0)
				{
					realIndex--;
					flag = true;
					break;
				}
			if (flag == true)
				continue;
			merge(realIndex);
		}
	}
}

void main1(void)
{

	size_t number = 30;
	arr_size = number;
	size_t** array = new size_t * [N] { 0 };
	for (size_t i = 0; i < N; i++)
		array[i] = new size_t[arr_size]{ 0 };

	array[0][0] = number;
	arr = array;
	clock_t t = clock();
	merge(0);
	t = clock() - t;

	cout << "time is - " << t << "\ncount - " << realIndex + 1;
}