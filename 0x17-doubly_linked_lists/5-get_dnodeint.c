#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head
 * @index: index of the node
 *
 * Return: the nth node else NULL if nth node does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int current_index = 0;
	dlistint_t *current_node = head;

	if (!current_node)
	{
		return (NULL);
	}

	while (current_node->prev)
	{
		current_node = current_node->prev;
	}

	while (current_node)
	{
		if (current_index == index)
			break;

		current_node = current_node->next;
		current_index++;
	}

	return (current_node);
}
