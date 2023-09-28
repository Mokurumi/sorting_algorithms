#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * get_min_max - Finds the minimum and maximum values in an array.
 * @array: The array to analyze
 * @size: The size of the array
 * @min: A pointer to store the minimum value
 * @max: A pointer to store the maximum value
 */
void get_min_max(int *array, size_t size, int *min, int *max)
{
	size_t i;
	*min = INT_MAX;
	*max = INT_MIN;

	for (i = 0; i < size; i++)
	{
		if (array[i] > *max)
			*max = array[i];
		if (array[i] < *min)
			*min = array[i];
	}
}

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int min, max, *count;
	size_t i, j;

	if (size < 2)
		return;

	get_min_max(array, size, &min, &max);

	count = malloc((max - min + 1) * sizeof(int));
	if (count == NULL)
		return;

	memset(count, 0, (max - min + 1) * sizeof(int));
	for (i = 0; i < size; i++)
		count[array[i] - min]++;

	j = 0;
	for (i = 0; i <= (size_t)(max - min); i++)
	{
		printf("%lu", (unsigned long)j);
		while (count[i] > 0)
		{
			array[j] = i + min;
			j++;
			count[i]--;
		}

		if (j < size || count[i] > 1)
			printf(", ");
		else
		{
			printf(", ");
			printf("%lu", (unsigned long)j);
			printf("\n");
		}

	}

	free(count);
}