#include "main.h"

/**
 * clear_bit - function to set bit at index to 0
 * @n: pointer to binary number
 * @index: position in n to set to 0
 *
 * Return: 1 if it works else -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 64)
		return (-1);
	*n &= ~(1UL << index);

	return (1);
}
