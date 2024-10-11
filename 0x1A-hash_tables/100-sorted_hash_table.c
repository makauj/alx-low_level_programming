#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * create_shash_node - Creates a new sorted hash node
 * @key: The key for the new node
 * @value: The value for the new node
 *
 * Return: A pointer to the newly created node
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;
	new_node->snext = NULL;
	new_node->sprev = NULL;

	return (new_node);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table
 * @key: The key of the element
 * @value: The value of the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *current;
	shash_node_t *new_node;
	shash_node_t *temp;

	if (!ht || !key || !value)
		return (0);

	index = hash_djb2((unsigned char *)key) % ht->size;
	current = ht->array[index];
	new_node = create_shash_node(key, value);
	/* If creating node failed */
	if (!new_node)
		return (0);

	/* Handle collision by chaining */
	if (current)
		new_node->next = current;

	ht->array[index] = new_node;

	/* Insert into sorted linked list */
	temp = ht->shead;
	while (temp && strcmp(temp->key, key) < 0)
	{
		temp = temp->snext;
	}

	/* If it's the first element */
	if (!temp)
	{
		if (!ht->shead)
			ht->stail = new_node;
		new_node->snext = ht->shead;
		if (ht->shead)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		new_node->snext = temp;
		new_node->sprev = temp->sprev;
		if (temp->sprev)
			temp->sprev->snext = new_node;
		else
			ht->shead = new_node;
		temp->sprev = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The hash table
 * @key: The key to look for
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (!ht || !key)
		return (NULL);

	index = hash_djb2((unsigned char *)key) % ht->size;
	current = ht->array[index];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the hash table in sorted order
 * @ht: The hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (!ht)
		return;

	current = ht->shead;
	printf("{");
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);
		current = current->snext;
		if (current)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the hash table in reverse order
 * @ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (!ht)
		return;

	current = ht->stail;
	printf("{");
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);
		current = current->sprev;
		if (current)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a hash table
 * @ht: The hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current;

	if (!ht)
		return;

	current = ht->shead;
	while (current)
	{
		shash_node_t *temp = current;

		current = current->snext;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
	free(ht->array);
	free(ht);
}
