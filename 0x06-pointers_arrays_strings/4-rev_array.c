#include "main.h"

/**
 * reverse_array - reverse an array of integers
 * @a: integer
 * @n: integer
 * Return: null
 */

void reverse_array(int *a, int n)
{
	int i, b;
	int j = n - 1;

	for (i = 0; i < j; i++, j--)
	{
		b = a[i];
		a[i] = a[j];
		a[j] = b;
	}
}
