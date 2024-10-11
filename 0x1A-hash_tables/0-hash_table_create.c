#include "hash_tables.h"

/**
 * hash_table_create - function creates a hash table
 * @size: size of the array
 *
 * Return: pointer to new table if successful else Null.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	hash_node_t *array;

	if (size < 1)
	{
		return (NULL);
	}

	new_table = malloc(sizeof(hash_table_t));
	if (!new_table)
		return (NULL);

	array = calloc(sizeof(new_table->array), size);
	if (!array)
		return (NULL);

	new_table->size = size;
	new_table->array = array;

	return (new_table);
}
