#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: returns 0 (Success)
 */
int main(void)
{
	int n;

	n = '0';

	while (n <= '9')
	{
		putchar (n);
		if (n != '9')
		{
			putchar(',');
			putchar(' ');
		}
		n++;
	}
	putchar ('\n');
	return (0);
}
