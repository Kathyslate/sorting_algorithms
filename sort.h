#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>


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

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *array, ssize_t item1, ssize_t item2);
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size);
void qs(int *array, ssize_t first, ssize_t last, int size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void change(int *array, int item1, int item2);
void cocktail_sort_list(listint_t **list);
void exchange(listint_t **head, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size);
void *my_calloc(unsigned int nmemb, unsigned int size);
void merger(int *arr, int *tmp, int start, int mid, int end);
void mergesort(int *array, int *tmp, int start, int end);
void merge_sort(int *array, size_t size);
void *new_calloc(unsigned int nmemb, unsigned int size);
void heap_sort(int *array, size_t size);
void maxHeapify(int *array, size_t size, int idx, size_t n);
void int_swap(int *a, int *b);
void radix_sort(int *array, size_t size);
void Sortcounts(int *arr, size_t n, int exp, int *output);
int getMaxArr(int *arr, int n);
void bitonic_sort(int *array, size_t size);
void sortbito(int arr[], int low, int nelemnt, int order, int size);
void mergebito(int arr[], int low, int nelemnt, int order);
void toswap(int arr[], int item1, int item2, int order);
void sort_quick(int *array, ssize_t first, ssize_t last, int size);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, int first, int last, int size);
void interchange(int *array, ssize_t item1, ssize_t item2);



#endif
