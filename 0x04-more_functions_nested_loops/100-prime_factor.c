#include <stdio.h>
#include <math.h>
/**
 * main - find the largest prime factor
 *
 * Return: null (Success)
 *
 */

int main(void)
{
	long n, j;

	n = 612852475143;

	for (j = 2; n > j; j++)
	{
		while (n % j == 0)
		{
			n = n / j;
		}
	}
	printf("%lu", n);
	putchar('\n');
	return (0);
}
