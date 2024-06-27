#include "main.h"

/**
 * print_diagonal - function prints a diagonal line int the terminal
 * @n: number of times _ should be printed
 * Return: null
 */
void print_diagonal(int n)
{
	int c, i;

	for (c = 0; c < n; c++)
	{
		for (i = 0; i <= c; i++)
		{
			if (i != c)
				_putchar(' ');
			else
				_putchar('\\');
		}
		_putchar('\n');
	}
	if (n <= 0)
		_putchar('\n');
}
