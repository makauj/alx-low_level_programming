#include <stdio.h>

/**
 * main - Entry point: Code that prints all possible combinations of two digits
 *
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i, j;

	for (i = 0; i <= 9; ++i)
	{
		for (j = i + 0; j <= 9; ++j)
		{
			putchar(i + '0');
			putchar(j + '0');
			putchar(',');
			putchar(' ');
		}
	}
	return (0);
}
