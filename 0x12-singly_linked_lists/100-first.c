#include <stdio.h>

/**
 * print_first - function to print before main
 *
 * Return: NULL
 */
void print_first(void) __attribute__((constructor));
void print_first(void)
{
	printf("You're beat! and yet, you must allow,\n
			I bore my house upon my back!\n");
}
