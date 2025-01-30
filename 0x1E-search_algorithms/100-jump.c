#include "search_algos.h"

/**
 * min - returns the minimum of two size_t values
 * @a: first value
 * @b: second value
 *
 * Return: minimum value
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * jump_search - searches for a value in a sorted array using Jump search
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: first index where value is, or -1 if not found or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, prev, curr;

	/* Check if array is NULL or empty */
	if (array == NULL || size == 0)
		return (-1);

	/* Calculate jump step using square root of size */
	step = sqrt(size);
	prev = 0;
	curr = step;

	/* Finding the block where element is present (if it's present) */
	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	while (curr < size && array[curr] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
		prev = curr;
		curr += step;
	}

	/* If we've gone beyond array bounds, adjust curr */
	if (curr >= size)
		curr = size;

	/* Print message about the range we're searching */
	printf("Value found between indexes [%lu] and [%lu]\n", prev, curr - 1);

	/* Linear search in the identified block */
	while (prev < curr)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		prev++;
	}
	return (-1);
}
