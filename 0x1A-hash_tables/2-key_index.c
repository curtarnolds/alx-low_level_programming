#include "hash_tables.h"


/**
 * key_index - Returns the index of a key.
 * @key: The key
 * @size: The size of the array of the hash table
 * Return: The index at which the key/value pair should be stored
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hashed_code, index;

	hashed_code = hash_djb2(key);
	index = hashed_code % size;

	return (index);
}
