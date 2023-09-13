#include "search_algos.h"


/**
 * jump_search - Search for a value in an array of integers using jump search
 * algorithm
 * @array: Array to be searched
 * @size: Size of the array
 * @value: Value to search for
 * Return: The index of the value or -1 if not found or array is NULL
 */
 int jump_search(int *array, size_t size, int value)
{
	size_t i, j;
	size_t jump = (size_t) sqrt(size);

	if (array == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i + jump] >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					i, i + jump);
			j = i;
			while (j <= i + jump)
			{
				printf("Value checked array[%lu] = [%d]\n", j, array[j]);
				if (array[j] == value)
					return (j);
				j++;
			}
		}
		i = i + jump;
	}
	return (-1);
}
