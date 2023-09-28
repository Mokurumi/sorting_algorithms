#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);
void swap_backward(listint_t **list, listint_t *current, int *swapped);

void counting_sort(int *array, size_t size);
void get_min_max(int *array, size_t size, int *min, int *max);

void merge_sort(int *array, size_t size);
void merge(int *arr, int *left, size_t left_sz, int *right, size_t right_sz);

void heap_sort(int *array, size_t size);
void swap(int *array, size_t size, int a, int b);
void sift_down(int *array, size_t size, size_t start, size_t end);

void radix_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);

void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t start, size_t size, int dir, size_t og_size);
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir, size_t og_size);

void quick_sort_hoare(int *array, size_t size);
void quicksort_hoare(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);


void swap_nodes(listint_t **left, listint_t **right);
void merge_sort_helper(int *array, int left, int right);
void copy_subarray(int *src, int src_start, int *dest, int n);

#endif /* SORT_H */
