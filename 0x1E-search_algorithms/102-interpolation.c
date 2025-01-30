#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array
 * using Interpolation search
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: first index where value is, or -1 if not found or array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;

	/* Check if array is NULL or empty */
	if (array == NULL || size == 0)
		return (-1);

	while (value < array[high] && value >= array[low] &&
			value <= array[high])
	{
		/* Calculate probe position */
		pos = low + (((double)(high - low) / (array[high] - array[low]))
				* (value - array[low]));

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	/* Value might be found at boundaries */
	if (value == array[low])
	{
		printf("Value checked array[%lu] = [%d]\n", low, array[low]);
		return (low);
	}
	/* Value not found or out of range */
	pos = low + (((double)(high - low) / (array[high] - array[low]))
                                * (value - array[low]));	
	printf("Value checked array[%lu] is out of range\n", pos);

	return (-1);
}
