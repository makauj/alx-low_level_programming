#include "lists.h"

/**
 * free_list - free a linked list
 * @head: pointer to head
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str); /* Free string */
		free(temp); /* free node */
	}
}
