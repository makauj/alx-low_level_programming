#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h: pointer to the head of the list
 *
 * Return: number of elements in list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}

/**
 * print_number - print an unsigned integer
 * @n: number to be printed
 */

void print_number(unsigned int n)
{
    if (n / 10)
        print_number(n / 10);
    _putchar((n % 10) + '0');
}
