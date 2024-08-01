#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
void print_first() __attribute__((constructor));
void print_first(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
