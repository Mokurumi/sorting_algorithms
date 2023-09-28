#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - Get the maximum value in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: The maximum value in the array.
 */
int getMax(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countingSort - Perform a counting sort on an array
 * based on a significant digit.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @exp: The current significant digit.
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix Sort
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
	}
}
