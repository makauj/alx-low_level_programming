#include "lists.h"

/**
 * add_nodeint_end - add a new node at the end of list
 * @head: pointer to pointer to head
 * @n: int add to new node
 *
 * Return: address to new node else NULL
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current = NULL;
	listint_t *add_node = NULL;

	add_node = malloc(sizeof(listint_t));

	if (add_node == NULL)
	{
		return (NULL);
	}

	add_node->n = n;
	add_node->next = NULL;

	if (*head  == NULL)
	{
		*head = add_node;
		add_node->next = NULL;
		return (add_node);
	}

	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = add_node;
	add_node->next = NULL;

	return (add_node);
}
