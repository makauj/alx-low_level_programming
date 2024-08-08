#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index
 * @n: unsigned integer
 * @index: index of the bit
 *
 * Return: value of the bit else -1
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int i;
	if (index >= 64)
	{
		return (-1);
	}

	i = ((n & (1UL << index)) ? 1 : 0);

	return (i);
}
