#include "monty.h"

/**
 * _realloc - a function that resizes dynamically allocated memory.
 * @ptr: old memory block to be resized.
 * @old_size: original size of ptr.
 * @new_size: the new size to make ptr.
 *
 * Return: address of allocated memory block or NULL.
 */
void *_realloc(void *ptr, int old_size, int new_size)
{
	int i; /* variable for indexing */
	char *new_ptr = NULL;

	if (!ptr) /* equivalent to ordinary malloc */
		return (malloc(new_size));
	if (!new_size) /* call to free ptr */
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size) /* nothing to do */
		return (ptr);

	/* if (new_size > old_size) */
	/* copy contents of old block to new block */
	new_ptr = malloc(sizeof(char) * new_size);
	if (new_ptr)
	{
		for (i = 0; i < old_size; ++i)
			new_ptr[i] = ((char *) ptr)[i];

		free(ptr);
	}

	return (new_ptr);
}
