#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number
 * @n: check for this character
 * Return: num
 */

int print_last_digit(int n)
{
	int num = n % 10;

	if (num < 0)
	{
		num = -num;
	}
	_putchar(num + '0');
	return (num);
}
