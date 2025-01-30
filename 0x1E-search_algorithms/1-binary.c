#include "search_algos.h"

/**
 * print_array - prints an array of integers
 * @array: pointer to the first element of the array
 * @start: starting index of the array to print
 * @end: ending index of the array to print
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search - searches for a value in a sorted array using Binary search
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found or array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;
	size_t mid;

	/* Check if array is NULL or empty */
	if (array == NULL || size == 0)
		return (-1);

	/* Binary search algorithm */
	while (left <= right)
	{
		printf("Searching in array: ");
		print_array(array, left, right);
		/* Calculate middle index */
		mid = (left + right) / 2;
		/* If value is found at middle */
		if (array[mid] == value)
			return (mid);

		/* If value is greater than middle, search right half */
		if (array[mid] < value)
			left = mid + 1;
		/* If value is less than middle, search left half */
		else
			right = mid - 1;
	}
	return (-1);
}
