#include "search_algos.h"


/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using interpolation search
 * @array: Pointer to the first element of the array to be searched in
 * @size: Size of the array to be searched in
 * @value: Value to search for
 * Return: The index of the where value is located, or -1 if value is not
 * found or array is NULL
*/
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, mid, high;

	if (array == NULL)
		return (-1);
	low = 0;
	high = size - 1;

	while (low <= high)
	{
		mid = low + (((double)(high - low) / (array[high] - array[low])) *
				(value - array[low]));
		if (mid <= size)
			printf("Value checked array[%lu] = [%d]\n", mid, array[mid]);
		else
		{
			printf("Value checked array[%lu] is out of range\n", mid);
			return (-1);
		}
		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}
