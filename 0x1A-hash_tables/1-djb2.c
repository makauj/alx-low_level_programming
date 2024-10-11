#include "hash_tables.h"

/**
 * hash_djb2 - implements djb2 as our function
 * @str: string
 *
 * Return: the hashed value
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	int c;
	unsigned long int hash;

	hash = 5381;
	while ((c = *str++))
	{
		/* hash * 33 + c */
		hash = ((hash << 5) + hash) + c;
	}
	return (hash);
}
