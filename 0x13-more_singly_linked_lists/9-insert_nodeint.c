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
	listint_t *add_node;
	listint_t *current = *head;
	listint_t *prev = NULL;

	add_node = malloc(sizeof(listint_t));
	if (add_node == NULL)
		return (NULL);
	add_node->n = n;
	add_node->next = NULL;

	if (idx == 0)
	{
		add_node->next = *head;
		*head = add_node;
		return (add_node);
	}

	while (current != NULL)
	{
		if (i == idx)
		{
			add_node->next = current;
			if (prev != NULL)
			{
				prev->next = add_node;
			}
			return (add_node);
		}
		prev = current;
		current = current->next;
		i++;
	}
	free(add_node);
	return (NULL);
}
