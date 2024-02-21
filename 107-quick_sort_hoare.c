#include "sort.h"
/**
 * quick_sort_hoare - quicksort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * description:  function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 */
void quick_sort_hoare(int *array, size_t size)
{
	sort_quick(array, 0, size - 1, size);
}

/**
 * sort_quick - sorting algorithm
 * @arr: array
 * @left: leftmost index
 * @right: rightmost index
 * @size: size of full array
 *
 * description:  function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 */
void sort_quick(int *arr, int left, int right, size_t size)
{
	int pivot;

	if ((right - left) < 2)
		return;
	pivot = pivot_split(arr, left, right, size);
	sort_quick(arr, left, pivot, size);
	sort_quick(arr, pivot, right, size);
}

/**
 * pivot_split - pivot and split
 * @arr: array
 * @left: leftmost index
 * @right:rightmost index
 * @size: size of full index
 * Return: pivot index
 *
 * description:  function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 */
int pivot_split(int *arr, int left, int right, size_t size)
{
	int i, i2, pivot, tmp;

	pivot = arr[right];
	i = left;
	i2 = right;

	while (1)
	{
		do i++;
		while (arr[i] < pivot);
		do i2--;
		while (arr[i2] > pivot);
		if (i < i2)
		{
			tmp = arr[i2];
			arr[i2] = arr[i];
			arr[i] = tmp;
			print_array(arr, size);
		}
		else
			return (i2);
	}
}
