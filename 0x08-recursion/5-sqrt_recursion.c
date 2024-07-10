#include "main.h"
int _sqrt_helper(int n, int i);
/**
 * _sqrt_recursion - finds the square root of a number
 * @n: number
 * Return: the square root of n
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}
/**
 * _sqrt_helper - recursion to find natural square root
 * @i: integer
 * @n: integer
 * Return: square root
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	if (i * i > n)
		return (-1);
	return (_sqrt_helper(n, i + 1));
}
