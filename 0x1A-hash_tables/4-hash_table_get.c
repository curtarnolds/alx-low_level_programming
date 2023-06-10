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
	hash_node_t *node;

	if (ht == NULL || key == NULL  || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->array[index];
	if (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		else
		{
			while (node->next)
			{
				node = node->next;
				if (strcmp(node->key, key) == 0)
					return (node->value);
			}
		}
	}
	return (NULL);
}
