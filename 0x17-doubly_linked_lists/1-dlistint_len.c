#include "lists.h"
/**
 * dlistint_len - function that returns the number of elements in a list
 * @h: pointer to the header
 *
 * Return: number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	int count = 0;
	const dlistint_t *current = h;

	if (!h)
	{
		return (0);
	}

	while (current)
	{
		current = current->next;
		count++;
	}

	return (count);
}
