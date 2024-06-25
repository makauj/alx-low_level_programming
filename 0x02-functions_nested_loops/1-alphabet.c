#include "main.h"

/**
 * print_alphabet - A function that prints the lower case alphabet
 *
 * Return: null (Success)
 */
void print_alphabet(void)
{
	char b;

	for (b = 'a'; b <= 'z'; b++)
		_putchar(b);
	_putchar('\n');
}
