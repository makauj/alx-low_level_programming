#include "main.h"

/**
 * array_range - function creates array of integers
 * @max: to of the range
 * @min: bottom of the range
 *
 * Return: pointer to new array else NULL
 */
int *array_range(int min, int max)
{
	int *arr;
	int i;
	int range = max - min + 1;

	if (min > max)
		return (NULL);
	arr = malloc(range * sizeof(int));
	if (arr == NULL)
		return (NULL);
	for (i = 0; i < range; i++)
	{
		arr[i] = min + i;
	}
	return (arr);
}
