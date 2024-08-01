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

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}

		h = h->next;
		count++;
	}

	return (count);
}
