#include "variadic_functions.h"

/**
 * sum_them_all - add all parameters/arguements
 * @n: constant integer
 *
 * Return: sum of parameters else 0
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list num;

	if (n == 0)
	{
		return (0);
	}
	va_start(num, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(num, int);
	}
	va_end(num);

	return (sum);
}
