#include "lists.h"

/**
 * insert_dnodeint_at_index - function that inserts a node at a given position
 * @h: pointer to pointer to the head
 * @idx: index of the list where new node will be added
 * @n: integer
 *
 * Return: The address to the new node, else NULL on failure
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = NULL;
	unsigned int i;
	dlistint_t *current;

	if (idx == 0)
	{
		new_node = add_dnodeint;
	}

	else
	{
		current = *h;
		i = 1;
		if (current)
		{
			while (current-> !=NULL)
				current = current->prev;
		}
		while (current)
		{
			if (i == idx)
			{
				if (current->next == NULL)
					new_node = add_dnodeint_end(h, n);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node)
					{
						new_node->n = n;
						new_node->next = current->next;
						new_node->prev = current;
						head->next->prev = new;
						head->next = new;
					}
				}
				break;
			}
			head = head->next;
			i++;
		}
	}
	return (new_node);
}
