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
	unsigned int count = 0;

	while (result)
	{
		count += reult & 1;
		result >>= 1;
	}

	return (count);
}
