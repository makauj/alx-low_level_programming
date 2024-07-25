#include "variadic_functions.h"

/**
 * print_all - prints all arguements
 * @format: list of arguements passed to the function
 * Return: nothing else (nil)
 */

void print_all(const char * const format, ...)
{
	va_list args;
	char *str;
	int i = 0;
	int first = 1; /*flag to manage comma placement*/

	va_start(args, format);
	while (format && format[i])
	{
		if (!first)
		{
			printf(", ");
		}
		first = 0; /*change flag after the first element*/
		/*check each character if format using a switch statement*/
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				printf("%s", str ? str : "(nil)");
				break;
			default:
				first = 1;/* Skip unrecognized format specifiers */
				break;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
