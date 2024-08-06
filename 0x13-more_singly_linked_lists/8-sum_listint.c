#include "lists.h"

/**
 * sum_listint - functio that gives the sum of all data
 * @head: pointer to the head
 *
 * Return: count
 */

int sum_listint(listint_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		count += head->n;
		head = head->next;
	}
	return (count);
}
