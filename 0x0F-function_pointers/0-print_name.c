#include "function_pointers.h"

/**
 * print_name - function that prints name
 * @name: string to be printed
 * @f: pointer to function print_name
 *
 * Description: This is a function that calls the pointer f
 * to the function print_name
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
