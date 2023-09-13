#include "search_algos.h"


void print_array(int *array, int start, int end);
/**
 * binary_search - Searches for a value in a sorted array of integers using
 * binary search
 * @array: Pointer to the first element of the array to be searched in
 * @size: Size of the array to be searched in
 * @value: Value to search for
 * Return: The index of the where value is located, or -1 if value is not
 * found or array is NULL
*/
int binary_search(int *array, size_t size, int value)
{
	int low, mid, high;

	if (array == NULL)
		return (-1);
	low = 0;
	high = size - 1;
	
	while (low <= high)
	{
		printf("Searching in array: ");
		print_array(array, low, high);
		mid = low + (high - low)/2;
		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}


/**
 * print_array - Print an array followed by a new line
 * @start: Start index to print
 * @end: End index to print
 * @array: The array to be printed
 */
void print_array(int *array, int start, int end)
{
	while (start <= end)
	{
		printf("%d", array[start]);
		if (start != end)
			printf(", ");
		start++;
	}
	printf("\n");
}
