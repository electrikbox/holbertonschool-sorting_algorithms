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
 * lomuto - partitions the array
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 * Return: index of pivot
*/
size_t lomuto(int *array, int low, int high, size_t size)
{
	int index, index0, pivot;

	index = low - 1;
	pivot = array[high];

	for (index0 = low; index0 < high; ++index0)
	{
		if (array[index0] < pivot)
		{
			index++;
			if (index != index0)
			{
				swap(&array[index], &array[index0]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[index + 1])
	{
		swap(&array[high], &array[index + 1]);
		print_array(array, size);
	}
	return (index + 1);
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
	size_t pi;

	if (low < high)
	{
		pi = lomuto(array, low, high, size);

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
