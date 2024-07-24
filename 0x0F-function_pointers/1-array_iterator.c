#include "function_pointers.h"

/**
 * array_iterator - Function that iterates an array
 * @array: array
 * @size: size of the array
 * @action: pointer to function
 *
 * Description: function that executes a function given
 * as a parameter on each element of an array.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array && action)
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
	else
		return;
}
