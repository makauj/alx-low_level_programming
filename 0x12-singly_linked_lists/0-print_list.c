#include "lists.h"

/**
 * print_list - function that prints all the elements in a linked list
 * @h: pointer to the head
 *
 * Return: number of nodes (count)
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;
	const char *nil_str = "(nil)";
	unsigned int i;
	int l, s;

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
				l = nil_str[i];
				putchar(l);
			}
		}
		else
		{
			for (i = 0; i < h->len; i++)
			{
				s = h->str[i];
				putchar(s);
			}
		}
		putchar('\n');
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * print_number - function to print a number
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
