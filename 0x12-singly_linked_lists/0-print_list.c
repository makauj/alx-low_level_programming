#include "lists.h"

/**
 * print_list - function that prints all the elements of a list
 * @h: pointer to the head
 *
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;
	const char *nil_str = "(nil)";
	unsigned int i;

	while (h != NULL)
	{
		putchar('[');
		print_number(h->len);
		putchar(']');
		putchar(' ');

		if (h->str == NULL)
		{
			for (i = 0; nil_str[i] != '\0'; i++)
			{
				putchar(nil_str[i]);
			}
		}
		else
		{
			for (i = 0; i < h->len; i++)
			{
				putchar(h->str[i]);
			}
		}
		putchar('\n');
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * print_number - function to print an unsigned integer
 * @n: the number to be printed
 */
void print_number(unsigned int n)
{
	if (n / 10)
	{
		print_number(n / 10);
	}
	putchar((n % 10) + '0');
}
