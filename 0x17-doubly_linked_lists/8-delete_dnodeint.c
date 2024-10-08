#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: double pointer to the head of the list
 * @index: index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		if (*head)
		{
			(*head)->prev = NULL;
		}
		free(current);
		return (1);
	}
	for (i = 0; current != NULL && i < index; i++)
	{
		current = current->next;
	}

	if (!current)
	{
		return (-1);
	}

	if (current->prev)
	{
		current->prev->next = current->next;
	}

	if (current->next)
	{
		current->next->prev = current->prev;
	}

	free(current);
	return (1);
}
