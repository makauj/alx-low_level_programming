#include "main.h"

/**
 * print_sign - checks if number is positive or negative
 * @n: check for this character
 * Return: 1 if positive, -1 if negative or 0 otherwise
 */

int print_sign(int n)
{
	if (n < '0')
	{
		_putchar('-');
		return (-1);
	}
	else if (n == '0')
	{
		_putchar(0);
		return (0);
	}
	else
	{
		_putchar('+');
		return (1);
	}
}
