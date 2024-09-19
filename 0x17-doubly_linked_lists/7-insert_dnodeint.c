#include "lists.h"

/**
 * insert_dnodeint_at_index - function that inserts a node at a given position
 * @h: pointer to pointer to the head
 * @idx: index of the list where new node will be added
 * @n: integer
 *
 * Return: The address to the new node, else NULL on failure
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	unsigned int i = 0;
	dlistint_t *current = *h;

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (idx == 0)
	{
		new_node->next = h;

		if (*h)
			(*h)->prev = new_node;

		*h = new_node;
		return (new_node);
	}

	for (i = 1; i < idx - 1 && current != NULL; i++)
		current = current->next;

	if (!current)
	{
		free(new_node);
		return (NULL);
	}

	new_node-next = current->next;
	new_node->prev = current;

	if (current->next)
		current->next->prev = new_node;

	current->next = new_node;

	return (new_node);
}
