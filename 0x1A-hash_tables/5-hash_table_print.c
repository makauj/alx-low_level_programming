#include "hash_tables.h"

/**
 * hash_table_print - prints hash table
 * @ht: hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int flag = 1;
	hash_node_t *temp;

	if (!ht)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp)
		{
			if (!flag)
			{
				printf(", ");
			}
			printf("'%s': '%s'", temp->key, temp->value);
			temp = temp->next;
			flag = 0;
		}
	}
	printf("}\n");
}
