#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always null (Success)
 */
int main(void)
{
	int c;
	int b;

	for (c = 'a'; c <= 'z'; ++c)
	{
		putchar(c);
	}
	for (b = 'A'; b <= 'Z'; ++b)
	{
		putchar(b);
	}
	putchar("\n");
	return (0);
}
