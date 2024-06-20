#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always null (Success)
 */
int main(void)
{
	/**
	 * Use sizeof(type) and %lu to find sizes of types
	 */
	printf("Size of a char: %lu bytes\n", sizeof(char));
	printf("Size of an int: %lu bytes\n", sizeof(int));
	printf("Size of a long int: %lu bytes\n", sizeof(long));
	printf("Size of a long long int: %lu bytes\n", sizeof(long long));
	printf("Size of a float: %lu bytes\n", sizeof(float));
	return (0);
}
