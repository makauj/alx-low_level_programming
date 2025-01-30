#include "search_algos.h"
/**
 * linear_search - function that searches for a value using Linear Search
 *
 * @array: pointer to first element
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: value
 */
int linear_search(int *array, size_t size, int value)
{
	size_t n;

	if (value == 0 || !array)
		return (-1);

	for (n = 0; n < size; n++)
	{
		printf("Value checked array[%li] = [%i]\n", n, array[n]);
		if (array[n] == value)
			return (n);
	}
	return (-1);
}
