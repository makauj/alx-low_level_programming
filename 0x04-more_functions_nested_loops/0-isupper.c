#include "main.h"

/**
 * _isupper - checks for uppercase character
 *
 * @c: check for this character
 * Return: 1 if lowercase, 0 otherwise
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
