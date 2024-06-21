#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always null (Success)
 */
int main(void)
{
	int c;

	for (c = 'c'; c < '15'; ++c)
	{
		putchar(c);
	}
	for (c = 'a'; c <= 'f'; ++c)
	{
		putchar(c);
	}
	putchar("\n");
	return (0);

}
