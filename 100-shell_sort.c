#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, gap = 1;

	if (array == NULL || size <= 1)
		return;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Iterate over decreasing gap sizes */
	while (gap > 0)
	{
		/* Perform insertion sort for the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			/*
			 * Shift elements in the current gap
			 * to find the correct position for temp
			 */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		/* Decrease the gap size following Knuth sequence */
		gap = (gap - 1) / 3;

		print_array(array, size);
	}
}
