#include "search_algos.h"


/**
 * linear_search - Searches for a value in an array using linear search
 * @array: The array to be searched
 * @size: The size of the array
 * @value: The value to be searched
 * Return: The index of the first occurence, else -1
*/
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
