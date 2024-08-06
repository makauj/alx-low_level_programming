#include "lists.h"

/**
 * pop_listint - delete node
 * @head: pointer to pointer to head
 *
 * Return: The head node's data (n) else 0 if empty
 */

int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}
	tmp = *head;
	n = tmp->n;
	*head = (*head)->next;
	free(tmp);

	return (n);
}
