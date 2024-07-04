#include <stdio.h>
#include "main.h"

/**
* print_number - prints an integer
* @n: integer
**/

void print_number(int n)
{
	unsigned int i;

	if (n < 0)
	{
		i = -n;
		_putchar('-');
	}
	else
		i = n;

	if (i > 9)
	{
		print_number(i / 10);
	}
	_putchar(i % 10 + '0');
}
