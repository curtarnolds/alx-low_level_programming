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
	char *dup_value;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	dup_value = strdup(value);
	if (dup_value == NULL)
		return (0);

	index = key_index((const unsigned char *) key, ht->size);
	for (i = index; i < ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = dup_value;
			return (1);
		}
	}

	new_node = create_node(key, dup_value);
	if (new_node == NULL)
		return (0);


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
		return (NULL);

	if (strlen(key) == 0)
		return (NULL);


	item->key = (char *) malloc(strlen(key) + 1);
	if (item->key == NULL)
		return (NULL);

	item->value = (char *) malloc(strlen(value) + 1);
	if (item->value == NULL)
	{
		free(item->key);
		return (NULL);
	}

	strcpy(item->key, key);
	strcpy(item->value, value);
	return (item);
}
