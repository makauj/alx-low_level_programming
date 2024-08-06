#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
    size_t node_count = 0;

    // Traverse the list and print each element
    while (h != NULL)
    {
        printf("%d\n", h->n);
        node_count++;
        h = h->next;
    }

    return node_count;
}
