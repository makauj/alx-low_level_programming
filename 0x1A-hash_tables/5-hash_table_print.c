#include "hash_tables.h"

/**
 * hash_table_print - prints hash table
 * @ht: hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	int i = 0, flag = 0;
	hash_node_t *array, *temp;

	if (!ht)
		return;

	printf("{");

	array = ht->array;
	while (i < ht->size)
	{
		temp = array[i];
		if (flag == 1 && temp)
			printf(", ");
		while (temp)
		{
			printf("'%s': '%s'", temp->key, temp->value);
			temp = temp->next;
			if (temp)
			{
				printf(", ");
			}
			flag = 1;
		}
		i++;
	}
	printf("}\n");
}
