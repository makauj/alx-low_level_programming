#include "main.h"

/**
 * more_numbers - function that prints 0 - 14, 10 times
 *
 * Return: null
 */

void more_numbers(void)
{
	int n, i;

	for (n = 0; n <= 9; n++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i >= 10)
				_putchar((i/10) + '0');
			_putchar((i % 10) + '0');
		}
		_putchar('\n');
	}
}
