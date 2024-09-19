#include "lists.h"

/**
 * add_dnodeint_end - create a new node at the end
 * @head: pointer to the pointer to the head
 * @n: data added to the new node
 *
 * Return: pointer to new node else NULL
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	dlistint_t *ptr = *head;

	if (!new_node)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;

		return (new_node);
	}

	while (ptr->next)
	{
		ptr = ptr->next;
	}

	ptr->next = new_node;
	new_node->prev = ptr;

	return (new_node);
}
