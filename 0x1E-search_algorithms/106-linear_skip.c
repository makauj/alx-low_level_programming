#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted linked list using Jump search
 * @list: pointer to the head of the linked list
 * @size: number of nodes in the list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, step_size;
	listint_t *prev, *curr;

	if (list == NULL || size == 0)
		return (NULL);
	/* Calculate jump step using square root of size */
	step_size = (size_t)sqrt(size);
	prev = list;
	curr = list;
	step = 0;
	/* Jump through the list */
	while (curr->index < size - 1 && curr->n < value)
	{
		/* Save previous position */
		prev = curr;
		for (step = 0; step < step_size && curr->next; step++)
			curr = curr->next;

		printf("Value checked at index [%lu] = [%d]\n",
				curr->index, curr->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, curr->index);
	/* Linear search in the identified range */
	while (prev && prev->index <= curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
