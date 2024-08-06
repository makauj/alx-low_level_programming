#include "lists.h"

/**
 * print_listint_safe - function prints a list
 * @head: pointer to head
 *
 * Return: The number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count1 = 0, count2;
	const listint_t *slow = head;
	const listint_t *fast;

	while (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);

		count1++;

		slow = slow->next;
		fast = head;

		for (count2 = 0; count2 < count1; count2++)
		{
			if (slow == fast)
			{
				printf("-> [%p] %d\n", (void *)slow, slow->n);
				return (count1);
			}

			fast = fast->next;
		}
	}
	return (count1);
}
