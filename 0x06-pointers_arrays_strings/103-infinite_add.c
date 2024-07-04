#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: The first number
 * @n2: The second number
 * @r: The buffer for storing the result
 * @size_r: The size of the buffer
 *
 * Return: If result can be stored in r, then r, otherwise 0
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1, l2, max_len, i;
	char d1, d2, c, rem, tmp;

	for (l1 = 0; *(n1 + l1) != '\0'; l1++)
		c = 0;
	for (l2 = 0; *(n2 + l2) != '\0'; l2++)
		rem = 0;
	max_len = l1 > l2 ? l1 : l2;
	i = max_len;
	if (size_r < max_len + 1)
		return (0);
	*(r + max_len) = '\0';
	i--;
	l1--;
	l2--;
	for (; i >= 0; i--)
	{
		d1 = l1 >= 0 ? *(n1 + l1) - '0' : 0;
		d2 = l2 >= 0 ? *(n2 + l2) - '0' : 0;
		rem = (d1 + d2 + c) % 10;
		c = (d1 + d2 + c) / 10;
		*(r + i) = (rem + '0');
		l1--;
		l2--;
	}
	if (c > 0 && size_r >= max_len + 2)
	{
		for (i = max_len + 1; i > 0; i--)
		{
			tmp = *(r + i);
			*(r + i) = *(r + i - 1);
			*(r + i - 1) = tmp;
		}
		*(r + i) = c + '0';
		return (r);
	}
	return ((c > 0 && size_r < max_len + 2) ? 0 : r);
}
