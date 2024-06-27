#include "main.h"
#include <stdio.h>

/**
 * print_numbers - write numbers 0 - 9
 *
 * Return: null (Success)
 */
void print_numbers(void)
{
	int n;

	for (n = 48; n <= 57; n++)
	{
		_putchar(n);
	}
	_putchar('\n');
}
