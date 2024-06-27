#include "main.h"

/**
 * _isdigit - checks for digits
 * @c: check for this character
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
