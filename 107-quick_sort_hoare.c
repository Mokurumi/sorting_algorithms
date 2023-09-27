#include "sort.h"

/**
 * hoare_partition - Partition array using Hoare's scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int temp, pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do
		{
			i++;
		}
		while (array[i] < pivot);

		do
		{
			j--;
		}
		while (array[j] > pivot);

		if (i >= j)
			return j;

		/* Swap array[i] and array[j] */
		if (i != j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
}

/**
 * quicksort_hoare - Recursive function to perform Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);

		quicksort_hoare(array, low, pivot, size);
		quicksort_hoare(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Entry point for Quick sort using Hoare's partition scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}
