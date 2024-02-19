#include "sort.h"
#include <stdio.h>


/**
 *new_calloc - this is a calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *new_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return ('\0');
	p = malloc(nmemb * size);
	if (p == NULL)
		return ('\0');
	for (i = 0; i < (nmemb * size); i++)
		p[i] = '\0';
	return (p);
}


/**
 *merger - make a merge
 *@arr: one from start to mid
 *@tmp: temp array used in merge
 *@start: first element position
 *@mid: array middle
 *@end: last element position
 **/
void merger(int *arr, int *tmp, int start, int mid, int end)
{
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	int left, right, i = 0;

	array_left = &tmp[0];
	array_right = &tmp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, i = start;
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}
	while (left < size_left)
		arr[i] = array_left[left], left++, i++;
	while (right < size_right)
		arr[i] = array_right[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}


/**
 *merge-sort - function that sorts an array of integers
 *@array: array of integers
 *@tmp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: fisrt element position
 *@end: last element position
 *Return: does not return
 */
void mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, tmp, start, mid);
		mergesort(array, tmp, mid + 1, end);
		merger(array, tmp, start, mid, end);
	}
}


/**
 *merge_sort - function that sorts an array of integers
 *@size: size of the list
 *@array: array of integers
 *Return: does not return
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = new_calloc(size, sizeof(int));
	mergesort(array, tmp, 0, size - 1);
	free(tmp);
}