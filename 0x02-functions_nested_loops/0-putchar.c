#include <stdio.h>

/**
 * main - function prints _putchar
 *
 * Return: null (Success)
 */
int main(void)
{
	char p[] = "_putchar";
	int n = 0;

	while (p[n] != '\0')
	{
		putchar(p[n]);
		n++;
	}
	putchar('\n');
	return (0);
}
