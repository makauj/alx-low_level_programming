#include "main.h"

/**
 * get_endianness - function that checks the endianess
 *
 * Return: 0 if big, 1 if little
 */

int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *) &x;

	if (*c == 1)
	{
		return (1); /* Little endian */
	}
	else
	{
		return (0); /* Big endian */
	}
}
