#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
    listint_t *head;
    listint_t *new;
    size_t n;

    // Test 1: Empty list
    printf("Test 1: Empty list\n");
    head = NULL;
    n = print_listint(head);
    printf("-> %lu elements\n\n", n);

    // Test 2: Single-node list
    printf("Test 2: Single-node list\n");
    head = create_node(42);
    if (head == NULL)
    {
        printf("Error\n");
        return (1);
    }
    n = print_listint(head);
    printf("-> %lu elements\n\n", n);
    free_listint(head);

    // Test 3: Multi-node list
    printf("Test 3: Multi-node list\n");
    head = create_node(1);
    if (head == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new = create_node(2);
    if (new == NULL)
    {
        printf("Error\n");
        free_listint(head);
        return (1);
    }
    new->next = head;
    head = new;
    new = create_node(3);
    if (new == NULL)
    {
        printf("Error\n");
        free_listint(head);
        return (1);
    }
    new->next = head;
    head = new;
    n = print_listint(head);
    printf("-> %lu elements\n\n", n);
    free_listint(head);

    // Test 4: Memory allocation failure (simulated)
    printf("Test 4: Memory allocation failure (simulated)\n");
    head = create_node(10);
    if (head == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new = create_node(20);
    if (new == NULL)
    {
        printf("Error\n");
        free_listint(head);
        return (1);
    }
    new->next = head;
    head = new;
    printf("Attempting to create node with insufficient memory...\n");
    // Simulate failure by not creating the next node.
    n = print_listint(head);
    printf("-> %lu elements\n\n", n);
    free_listint(head);

    return (0);
}
