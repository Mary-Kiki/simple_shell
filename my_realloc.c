#include "shell.h"
/**
 * my_realloc -resizes the pointer which was previously allocated
 * @ptr: the pointer previously allocated
 * @old_size: old size of the pointer
 * @new_size: new_size of the pointer
 * Return: new pointer to memory block
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nwptr;
	unsigned int c;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		nwptr = malloc(new_size);
		if (nwptr == NULL)
			return (NULL);
		return (nwptr);
	}
	else
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	nwptr = malloc(new_size);

	if (nwptr == NULL)
		return (NULL);

	for (c = 0; c < old_size && c < new_size; c++)
	{
		nwptr[c] = ((char *) ptr)[c];
	}

	free(ptr);
	return (nwptr);
}
