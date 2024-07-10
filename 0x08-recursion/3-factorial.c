#include "main.h"

/**
 * factorial - return factorial of a given number
 * @n: number
 * Return: null
 */

int factorial(int n)
{
	if (n <= 1)
	{
		return (1);
	}
	return (n * factorial(n - 1));
}
