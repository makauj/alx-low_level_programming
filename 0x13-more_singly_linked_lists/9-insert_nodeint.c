#include "lists.h"

/**
 * insert_nodeint_at_index - function to insert a new node at a give position
 * @head: double pointer to head
 * @idx: index where new node should be added in list
 * @n: integer
 *
 * Return: address of the new node else NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	size_t i = 0;
	listint_t *current;
	listint_t *new;

	new = malloc(sizeof(listint_t));

	if (head == NULL || new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = NULL;

	if (!idx)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	current = *head;

	while (current)
	{
		if (i == (idx - 1))
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		i++;
		current = current->next;
	}
	free(new);

	return (NULL);
}
