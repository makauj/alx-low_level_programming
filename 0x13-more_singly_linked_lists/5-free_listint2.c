#include "lists.h"

/**
 * free_listint2 - function frees a listint_t list and sets *head to NULL
 * @head: pointer to the head of the list
 */

void free_listint2(listint_t **head)
{
	listint_t *new_node1 = NULL, *new_node2 = NULL;

	if (head == NULL)
	{
		return;
	}
	new_node1 = *head;

	while (new_node1 != NULL)
	{
		new_node2 = new_node1;
		new_node1 = new_node1->next;
		free(new_node2);
	}
	*head = NULL;
}
