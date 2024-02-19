#include "sort.h"
#include <stdlib.h>
#include <stdio.h>


/**
 *my_calloc - this is a calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *my_calloc(unsigned int nmemb, unsigned int size)
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
 * counting_sort - sorts an array
 * @array: Array to be sorted
 * @size: size of the array
 *
 * Return: void
 *
 * description: sorts an array of integers in ascending order
 * using the Counting sort algorithm
 */
void counting_sort(int *array, size_t size)
{
	int index, maximun = 0, *counter = '\0', *tmp = '\0';
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > maximun)
			maximun = array[i];
	counter = my_calloc(maximun + 1, sizeof(int));
	tmp = my_calloc(size + 1, sizeof(int));
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	for (index = 1; index <= maximun; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximun + 1);
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}
