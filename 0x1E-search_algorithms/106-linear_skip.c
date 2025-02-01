#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr, *prev;

	if (list == NULL)
		return (NULL);

	curr = list;
	prev = list;

	while (curr->express && curr->n < value)
	{
		prev = curr;
		curr = curr->express;
		printf("Value checked at index [%lu] = [%d]\n",
				curr->index, curr->n);
	}
	if (curr->express == NULL && curr->n < value)
	{
		prev = curr;
		while (curr->next)
			curr = curr->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, curr->index);

	curr = prev;
	while (curr && curr->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				curr->index, curr->n);
		if (curr->n == value)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
