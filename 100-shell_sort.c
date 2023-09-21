#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array of elements
 * @size: size of the array
 *
*/

void shell_sort(int *array, size_t size)
{
	int temp;
	size_t index, gap, n;

	gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (index = gap; index < size; index += 1)
		{
			temp = array[index];

			for (n = index; n >= gap && temp < array[n - gap]; n -= gap)
				array[n] = array[n - gap];
			array[n] = temp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
