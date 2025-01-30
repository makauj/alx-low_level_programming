#include <stdio.h>
/**
 * advance_binary_recursion - Recursive function to perform binary search
 * @array: Pointer to the first element of the array
 * @low: The low index of the subarray
 * @high: The high index of the subarray
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value or -1 if not found
 */
int advance_binary_recursion(int *array, int value,
			    size_t low, size_t high)
{
	size_t mid, i;

	if (!array)
		return (-1);

	mid = (low + high) / 2;
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%i%s", array[i], i == high ? "\n" : ", ");

	if (array[low] == value)
		return ((int)low);

	if (array[low] != array[high])
	{
		if (array[mid] < value)
			return (advance_binary_recursion(array, value,
							mid + 1, high));
		if (array[mid] >= value)
			return (advance_binary_recursion(array, value,
							low, mid));
	}

	return (-1);
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
	if (!array)
		return (-1);

	return (advance_binary_recursion(array, value, 0, size - 1));
}
