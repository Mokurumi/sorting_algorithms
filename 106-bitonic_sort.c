#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bitonic_merge - Merges two sub-arrays in bitonic order
 * @array: The original array
 * @start: Starting index of the sub-array
 * @size: Size of the sub-array to be merged
 * @dir: Direction of sorting (1 for increasing, 0 for decreasing)
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
	size_t half = size / 2;
	size_t i, temp;

	if (size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n",
				size, size, (dir == 1) ? "UP" : "DOWN");
		print_array(array + start, size);

		for (i = start; i < start + half; i++)
		{
			if ((array[i] > array[i + half] && dir == 1) ||
				(array[i] < array[i + half] && dir == 0))
			{
				temp = array[i];
				array[i] = array[i + half];
				array[i + half] = temp;
			}
		}

		bitonic_merge(array, start, half, dir);
		bitonic_merge(array, start + half, half, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts the bitonic sequence
 * @array: The original array
 * @start: Starting index of the sub-array
 * @size: Size of the sub-array to be sorted
 * @dir: Direction of sorting (1 for increasing, 0 for decreasing)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
	size_t half = size / 2;

	if (size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n",
				size, size, (dir == 1) ? "UP" : "DOWN");
		print_array(array + start, size);

		bitonic_sort_recursive(array, start, half, 1);
		bitonic_sort_recursive(array, start + half, half, 0);

		bitonic_merge(array, start, size, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
