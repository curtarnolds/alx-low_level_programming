#include "hash_tables.h"


/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to update
 * @key: The key. (cannot be an empty string)
 * @value: The value associated with the key.
 * Return: 1 on success. 0 otherwise
 *
 * In case of collision, a new node is added at the beginning of the list
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	char *value_copy, *key_copy;
	hash_node_t *node, *new_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);
	index = key_index((const unsigned char *) key, ht->size);
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	node = ht->array[index];
	while (node)
	{
		if (strcmp(key, node->key) == 0)
		{
			free(node->value);
			node->value = value_copy;
			return (1);
		}
		node = node->next;
	}
	key_copy = strdup(key);
	if (key_copy == NULL)
	{
		free(value_copy);
		return (0);
	}
	new_node = (hash_node_t *) malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(key_copy);
		free(value_copy);
		return (0);
	}
	new_node->key = key_copy;
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
