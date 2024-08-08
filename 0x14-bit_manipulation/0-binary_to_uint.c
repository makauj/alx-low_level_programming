#include "main.h"

/**
 * binary_to_uint - function to convert binary number to decimal
 * @b: pointer to the binary number
 *
 * Return: converted decimal number as unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int dec = 0;
	unsigned int i = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (b[i] != 0)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}
		dec <<= 1;
		if (b[i] & 1)
		{
			dec += 1;
		}
		i += 1;
	}

	return (dec);
}
