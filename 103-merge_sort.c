#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sub-arrays into one sorted array
 * @arr: The original array
 * @left: Pointer to the left sub-array
 * @left_sz: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_sz: Size of the right sub-array
 */
void merge(int *arr, int *left, size_t left_sz, int *right, size_t right_sz)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((left_sz + right_sz) * sizeof(int));

	if (temp == NULL)
		return;
	printf("Merging...\n[left]: ");
	print_array(left, left_sz);
	printf("[right]: ");
	print_array(right, right_sz);
	while (i < left_sz && j < right_sz)
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		}
		else
		{
			temp[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_sz)
	{
		temp[k] = left[i];
		i++;
		k++;
	}
	while (j < right_sz)
	{
		temp[k] = right[j];
		j++;
		k++;
	}
	for (i = 0; i < left_sz + right_sz; i++)
		arr[i] = temp[i];
	printf("[Done]: ");
	print_array(arr, left_sz + right_sz);
	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t middle = 0;
	int *left = NULL;
	int *right = NULL;

	if (size < 2 || array == NULL)
		return;

	middle = size / 2;

	left = array;
	right = array + middle;

	merge_sort(left, middle);
	merge_sort(right, size - middle);

	merge(array, left, middle, right, size - middle);
}
