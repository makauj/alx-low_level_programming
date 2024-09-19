#include "lists.h"

/**
 * sum_dlistint - function that returns the sum of the data in a linked list
 * @head: pointer to the head of the list
 *
 * Return: sum of the data, else 0 if list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (!head)
		return (0);

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
