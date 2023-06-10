#include "hash_tables.h"
#include <stdio.h>


/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key you are looking for
 * Return: The value associated with the element or NULL
 * if key couldn't be found
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;

	if (ht == NULL || key == NULL  || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);
	if (index >= ht->size)
		return (NULL);

	if (ht->array[index] != NULL)
	{
		if (ht->array[index]->next)
		{
			while (ht->array[index]->next)
			{
				if (strcmp(ht->array[index]->key, key) == 0)
					return (ht->array[index]->value);
			}
		}
		if (strcmp(ht->array[index]->key, key) == 0)
			return (ht->array[index]->value);
	}
	return (NULL);
}
