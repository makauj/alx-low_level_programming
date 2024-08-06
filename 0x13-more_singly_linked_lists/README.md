Sure! Here's a comprehensive `README.md` for your GitHub repository, covering the functions and tasks related to handling linked lists in C.

```markdown
# Linked Lists in C

This repository contains various functions to manipulate `listint_t` linked lists in C. These functions cover creating, adding, freeing, reversing, and detecting loops in linked lists.

## Table of Contents

- [Description](#description)
- [Usage](#usage)
- [Functions](#functions)
  - [print_listint](#print_listint)
  - [add_nodeint](#add_nodeint)
  - [free_listint](#free_listint)
  - [get_nodeint_at_index](#get_nodeint_at_index)
  - [insert_nodeint_at_index](#insert_nodeint_at_index)
  - [reverse_listint](#reverse_listint)
  - [free_listint_safe](#free_listint_safe)
  - [print_listint_safe](#print_listint_safe)
  - [find_listint_loop](#find_listint_loop)
- [Compilation](#compilation)
- [Examples](#examples)

## Description

This project provides a set of functions to work with singly linked lists of integers (`listint_t`). Each function is designed to perform specific tasks such as printing the list, adding nodes, freeing nodes, reversing the list, and handling lists with loops.

## Usage

To use these functions, include the provided header file `lists.h` in your project and link against the compiled object files.

## Functions

### `print_listint`

Prints all the elements of a `listint_t` list.

```c
size_t print_listint(const listint_t *h);
```

### `add_nodeint`

Adds a new node at the beginning of a `listint_t` list.

```c
listint_t *add_nodeint(listint_t **head, const int n);
```

### `free_listint`

Frees a `listint_t` list.

```c
void free_listint(listint_t *head);
```

### `get_nodeint_at_index`

Returns the nth node of a `listint_t` linked list.

```c
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
```

### `insert_nodeint_at_index`

Inserts a new node at a given position.

```c
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);
```

### `reverse_listint`

Reverses a `listint_t` linked list.

```c
listint_t *reverse_listint(listint_t **head);
```

### `free_listint_safe`

Frees a `listint_t` list safely (handles loops).

```c
size_t free_listint_safe(listint_t **h);
```

### `print_listint_safe`

Prints a `listint_t` list safely (handles loops).

```c
size_t print_listint_safe(const listint_t *head);
```

### `find_listint_loop`

Finds the loop in a linked list.

```c
listint_t *find_listint_loop(listint_t *head);
```

## Compilation

To compile the functions, you can use `gcc` as follows:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=c99 *.c -o list
```

This will compile all `.c` files in the directory into an executable named `list`.

## Examples

### Example 1: Adding and Printing Nodes

```c
#include "lists.h"

int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    print_listint(head);
    free_listint(head);
    return (0);
}
```

### Example 2: Reversing a List

```c
#include "lists.h"

int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    head = reverse_listint(&head);
    print_listint(head);
    free_listint(head);
    return (0);
}
```

### Example 3: Detecting a Loop

```c
#include "lists.h"

int main(void)
{
    listint_t *head;
    listint_t *node;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    node = head->next->next; /* point to the 2nd node */
    node->next = head; /* create a loop */

    if (find_listint_loop(head) != NULL)
        printf("Loop detected\n");
    else
        printf("No loop detected\n");

    free_listint_safe(&head);
    return (0);
}
```
