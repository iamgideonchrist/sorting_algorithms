#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: The array to be sorted
 * @size: Size of @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (size == 0 || size == 1)
		return;

	while (gap < size)
		gap = gap * 3 + 1;

	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
			i++;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
