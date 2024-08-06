#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at index index
 * @head: double pointer to the head
 * @index: index of the node to be deleted
 *
 * Return: 1 if successful else -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head;
	listint_t *tmp = NULL;
	size_t i;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	for (i = 0; current != NULL && i < index - 1; i++)
	{
		current = current->next;
	}

	if (current == NULL || current->next == NULL)
	{
		return (-1);
	}

	tmp = current->next;
	current->next = tmp->next;
	free(tmp);

	return (1);
}

