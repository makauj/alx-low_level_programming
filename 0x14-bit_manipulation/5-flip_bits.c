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

	while (result != 0) /*Loop as long as there are bits in result*/
	{
		result &= (result - 1); /* Clear the lowest set bit */
		count += 1; /*Increment the count*/
	}

	return (count);
}
