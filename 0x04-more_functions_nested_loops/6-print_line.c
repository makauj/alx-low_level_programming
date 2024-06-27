#include "main.h"

/**
 * print_line - function prints a straight line int the terminal
 * @n: number of times _ should be printed
 * Return: null
 */
void print_line(int n)
{
	int c;

	for (c = 0; c < n; c++)
		_putchar('_');

	_putchar('\n');
}
