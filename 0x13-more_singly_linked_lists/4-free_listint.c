#include "lists.h"

/**
 * free_listint - function to free listint_t
 * @head: pointer to the head of the list
 */

void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
