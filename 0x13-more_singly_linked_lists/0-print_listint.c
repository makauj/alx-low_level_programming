#include "lists.h"

/**
 * print_listint - function that prints all the the elements of a list
 * @h: head of the node
 *
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
