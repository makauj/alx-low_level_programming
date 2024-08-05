#include "lists.h"

/**
 * listint_len - function to find the length of a list
 * @h: head
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	int count = 0;
	const listint_t *current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}