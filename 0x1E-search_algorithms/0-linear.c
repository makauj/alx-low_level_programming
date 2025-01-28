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
	int n;

	if (!value || array == NULL)
		return (-1);

	for (n = 0; n < size; n++)
	{
		if (array[n] == value)
			return (n);
	}
	return (-1);
}
