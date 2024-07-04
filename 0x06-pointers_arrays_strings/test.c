#include "main.h"

/**
 * print_number - print integer
 * @n: integer
 * Return: null
 */

void print_number(int n)
{
	int num, div, digit;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}
	div = 1;
	while (num / div >= 10)
	{
		div *= 10;
	}

	while (div > 0)
	{
		digit = num / div;
		_putchar(digit + '0');
		num %= div;
		div /= 10;
	}
}
