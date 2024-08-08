#include "main.h"

/**
 * set_bit - function that set's a bit at index to 1
 * @n: pointer to binary number
 * @index: position of the bit you want to set
 *
 * Return: 1 else -1 if it fails
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 64)
	{
		return (-1);
	}

	*n |= (1UL << index);

	return (1);
}
