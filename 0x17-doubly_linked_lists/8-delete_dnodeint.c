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
	dlistint_t *curr = *head;
	unsigned int i = 0;

	if (!curr)
		return (-1);

	for (i = 0; curr != NULL && i < index; i++)
		curr = curr->next;

	if (curr)
		while (curr->prev != NULL)
			curr = curr->prev;

	if (curr == NULL)
		return (-1);

	if (curr->prev)
		curr->prev->next = curr->next;

	if (curr->next)
		curr->next->prev = curr->prev;

	if (index == 0)
		*head = curr->next;

	free(curr);

	return (1);
}
