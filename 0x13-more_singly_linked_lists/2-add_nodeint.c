#include "lists.h"

/**
 * add_nodeint - function that adds a node to list
 * @head: pointer to a pointer to head
 * @n: number of nodes
 *
 * Return: pointer to a new node else NULL on failure
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *add_node;

	if (head == NULL)
	{
		return (NULL);
	}
	add_node = malloc(sizeof(listint_t));

	if (!add_node)
	{
		return (NULL);
	}

	add_node->n = n;
	add_node->next = *head;
	*head = add_node;

	return (add_node);
}
