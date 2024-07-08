#include "main.h"
/**
 * print_diagsums - main fuction
 * @size: function
 * @a: function
 */
void print_diagsums(int *a, int size)
{
	int c1 = 0;
	int c2 = 0;
	int x;

	for (x = 0; x < size; x++)
	{
		c1 = c1 + a[x * size + x];
	}
	for (x = size - 1; x >= 0; x--)
	{
		c2 += a[x * size + (size - x - 1)];
	}
	printf("%d, %d\n", c1, c2);
}
