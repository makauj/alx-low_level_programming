#include "main.h"

/**
 * print_triangle - print a triangle
 *
 * @size: size of triangle
 * Return: null
 */
void print_triangle(int size)
{
	int c, s, i;

	for (c = 0; c < size; c++)
	{
		for (i = 0; i < size; i++)
		{
			s = size - c - 1;
			if (i < s)
				_putchar(' ');
			else
				_putchar('#');
		}
		_putchar('\n');
	}
	if (size <= 0)
		_putchar('\n');
}
