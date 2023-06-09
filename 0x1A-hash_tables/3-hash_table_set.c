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
	hash_node_t *new_node, *node_exists;
	unsigned long int index;

	new_node = create_node(key, value);
	index = key_index((const unsigned char *) key, ht->size);

	node_exists = ht->array[index];

	if (node_exists == NULL)
	{
		ht->array[index] = new_node;
	}
	else
	{
		new_node->next = node_exists;
		ht->array[index] = new_node;
	}

	return (1);
}


/**
 * create_node - Creates an item in hash_table_t
 * @key: The key of the item
 * @value: The value of the item
 * Return: The pointer to the created item
*/
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *item = (hash_node_t *) malloc(sizeof(hash_node_t));

	if (item == NULL)
		return (0);

	if (strlen(key) == 0)
		return (0);


	item->key = (char *) malloc(strlen(key) + 1);
	if (item->key == NULL)
		return (0);

	item->value = (char *) malloc(strlen(value) + 1);
	if (item->value == NULL)
	{
		free(item->key);
		return (0);
	}

	strcpy(item->key, key);
	strcpy(item->value, value);
	return (item);
}
