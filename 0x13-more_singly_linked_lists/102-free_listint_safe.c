#include "lists.h"

/**
* free_listint_safe - function that frees a list
* @h: double pointer to head
*
* Return: size of freed list
*/

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *new_node;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}

	while (*h != NULL)
	{
		new_node = (*h)->next;
		free(*h);
		count++;

		if (new_node >= *h)
		{
			*h = NULL;
			break;
		}
		*h = new_node;
	}

	*h = NULL;

	return (count);
}
