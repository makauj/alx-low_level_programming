#include "search_algos.h"

/**
 * print_array - prints an array between two indices
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
 * binary_recursive - recursively searches for first occurrence of value
 * @array: pointer to the first element of the array
 * @left: left boundary of search
 * @right: right boundary of search
 * @value: value to search for
 *
 * Return: index of first occurrence of value, or -1 if not found
 */
int binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	/* Base case: if boundaries cross */
	if (left > right)
		return (-1);

	/* Print current subarray */
	print_array(array, left, right);

	/* Calculate middle point */
	mid = left + (right - left) / 2;

	/**
	 * If mid is 0 or value at mid-1 is different from value,
	 * and value at mid equals search value, we found first occurrence
	 */
	if ((mid == 0 || array[mid - 1] < value) && array[mid] == value)
		return (mid);

	/**
	 * If value at mid is greater than or equal to search value,
	 * search in left subarray to find first occurrence
	 */
	if (array[mid] >= value)
		return (binary_recursive(array, left, mid, value));

	/* Search in right subarray */
	return (binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - searches for first occurrence of a value in a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index of first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	/* Check if array is NULL or empty */
	if (array == NULL || size == 0)
		return (-1);

	/* Call recursive helper function */
	return (binary_recursive(array, 0, size - 1, value));
}
