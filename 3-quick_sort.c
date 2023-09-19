#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions the array
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 * Return: index of pivot
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);

	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_helper - sorts the array
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: size of array
*/
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts the array
 * @array: array
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
