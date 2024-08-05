#include "lists.h"

/**
 * print_listint - function that prints all the the elements of a list
 * @h: head of the node
 *
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{
	const listint_t *current = h;
	size_t count = 0;

	while (current != NULL)
	{
		printf("%d \n", current->n);
		current = current->next;
		count++;
	}
	printf("\n");

	return (count);
}
