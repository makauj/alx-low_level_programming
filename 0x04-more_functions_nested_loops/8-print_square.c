#include "main.h"

/**
 * print_square - function prints a square in the terminal
 * @size: number of times _ should be printed
 * Return: null
 */

void print_square(int size)
{
	int c, i;

	if (size <= 0)
		_putchar('\n');
	for (c = 0; c < size; c++)
	{
		for (i = 0; i <= size; i++)
			_putchar('#');
		_putchar('\n');
	}
}
