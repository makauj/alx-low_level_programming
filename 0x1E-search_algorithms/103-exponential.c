#include "search_algos.h"

/**
 * print_array - prints an array of integers
 * @array: pointer to the first element of the array
 * @left: starting index
 * @right: ending index
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_exp - binary search for exponential search
 * @array: pointer to the first element of the array
 * @left: starting index
 * @right: ending index
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */
int binary_search_exp(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	while (left <= right)
	{
		print_array(array, left, right);
		mid = (left + right) / 2;

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array using
 * Exponential search
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: first index where value is, or -1 if not found or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t j = 1;
	size_t right;

	/* Check if array is NULL or empty */
	if (array == NULL || size == 0)
		return (-1);

	/* If first element is the value */
	if (array[0] == value)
		return (0);

	/* Find range for binary search using exponential growth */
	while (j < size && array[j] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", j, array[j]);
		j *= 2;
	}

	/* Set right boundary for binary search */
	right = (j < size) ? j : size - 1;
	/* Print the range we're searching in */
	printf("Value found between indexes [%lu] and [%lu]\n", j / 2, right);

	/* Perform binary search on the found range */
	return (binary_search_exp(array, j / 2, right, value));
}
