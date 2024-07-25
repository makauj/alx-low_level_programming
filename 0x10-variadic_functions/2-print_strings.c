#include "variadic_functions.h"

/**
 * print_strings - function prints strings
 * @separator: string printed between strings
 * @n: number of arguements passed to function
 *
 * Return: nothing
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *str = 0;
	va_list args;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str != NULL)
		{
			printf("%s", str);
		}
		else
			printf("(nil)");

		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}
	va_end(args);

	printf("\n");
}
