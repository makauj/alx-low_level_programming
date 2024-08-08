#include "main.h"

/**
 * flip_bits - function to flip bits
 * @n: first number
 * @m: Second number
 *
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int result = n ^ m;
	unsigned long int count = 0;

	while (count != 0)
	{
		result &= (result - 1);
		count += 1;
	}

	return (count);
}
