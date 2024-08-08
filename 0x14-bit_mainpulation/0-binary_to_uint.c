#include "main.h"

/**
 * binary_to_unit - function to convert binary number to decimal
 * @b: pointer to the binary number
 *
 * Return: converted decimal number as unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int dec = 0;
	unsigned int rem = 1;
	int i, len = 0;

	if (b == NULL)
	{
		return (0);
	}
	len = strlen(b);
	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] == '1')
		{
			dec += rem;
		}
		rem *= 2;
	}

	return (dec);
}
