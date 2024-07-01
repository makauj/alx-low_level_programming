#include "main.h"
#include <string.h>

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: char
 *
 */

void print_rev(char *s)
{
	int i;
	int r = 0;

	for (i = 0; s[i] != '\0'; i++)
		r++;
	for (i = r - 1; i >= 0; i--)
		_putchar(s[i]);
	_putchar('\n');
}
