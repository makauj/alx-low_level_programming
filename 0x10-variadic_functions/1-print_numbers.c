#include "variadic_functions.h"

/**
 * print_numbers - Function to print numbers
 * @separator: string between numbers
 * @n: number of integers passed to the function
 *
 * Description: This is a variadic function that prints numbers
 * with a comma and a space between them.
 *
 * Return: 0
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list op;
	unsigned int i;
	int list;

	va_start(op, n);

	for (i = 0; i < n; i++)
	{
		list = va_arg(op, int);
		printf("%d", list);

		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}
	va_end(op);

	printf("\n");
}
