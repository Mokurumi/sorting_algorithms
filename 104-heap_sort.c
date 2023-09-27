#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array.
 * @array: The array containing the integers.
 * @size: The size of the array.
 * @a: Index of the first integer to swap.
 * @b: Index of the second integer to swap.
 */
void swap(int *array, size_t size, int a, int b)
{
	int temp;

	if (a != b)
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * sift_down - Moves a node down the heap to its correct position.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @start: The index of the node to sift down.
 * @end: The maximum index where the node can be placed.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child, swap_index;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap_index = root;

		if (array[swap_index] < array[child])
			swap_index = child;

		if (child + 1 <= end && array[swap_index] < array[child + 1])
			swap_index = child + 1;

		if (swap_index == root)
			return;

		swap(array, size, root, swap_index);
		root = swap_index;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, (size_t)i, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, 0, i);
		sift_down(array, size, 0, i - 1);
	}
}
