#include <stdio.h>

/**
 * print_subarray - Print the current subarray
 * @array: Pointer to the first element of the array
 * @low: The low index of the subarray
 * @high: The high index of the subarray
 */
void print_subarray(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(" ");
	}

	printf("\n");
}

/**
 * advance_binary_recursive - Recursive function to perform binary search
 * @array: Pointer to the first element of the array
 * @low: The low index of the subarray
 * @high: The high index of the subarray
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value or -1 if not found
 */
int advance_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid = low + (high - low) / 2;

	if (low > high)
		return (-1);

	print_subarray(array, low, high);

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		return (advance_binary_recursive(array, low, mid - 1, value));
	}
	else if (array[mid] < value)
	{
		return (advance_binary_recursive(array, mid + 1, high, value));
	}
	else
	{
		return (advance_binary_recursive(array, low, mid - 1, value));
	}
}

/**
 * advanced_binary - Initiates the recursive binary search
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advance_binary_recursive(array, 0, size - 1, value));
}
