#include "main.h"

/**
 * puts_half - print half of a string
 * @str: character string
 *
 */

void puts_half(char *str)
{
	int i;
	int count = 0;
	int n;

	for (i = 0; str[i] != '\0'; i++)
	{
		count++;
	}

	n = (count - 1) / 2;

	for (i = n + 1; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
