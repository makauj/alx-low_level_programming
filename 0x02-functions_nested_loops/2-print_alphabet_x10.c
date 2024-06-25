#include "main.h"

/**
 * print_alphabet_x10 - print lowercase alphabet 10 times
 *
 * Return: null
 */

void print_alphabet_x10(void)
{
	int n;
	char a;

	for (n = 0; n < 10; n++)
	{
		for (a = 'a'; a <= 'z'; a++)
			_putchar(a);
	}
	_putchar('\n');
}
