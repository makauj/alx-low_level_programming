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
	dlistint_t *curr = *head, *temp;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(curr);
	}
	for (i = 0; curr != NULL && i < index; i++)
	{
		curr = curr->next;
	}

	if (curr == NULL || curr->next == NULL)
	{
		return (-1);
	}
	temp = curr->next;
	if (curr->next->next == NULL)
	{
		curr->next = NULL;
		free(temp);
	}
	else
	{
		curr->next = curr->next->next;
		temp->next->prev = temp;
		free(temp);
	}

	return (1);
}
