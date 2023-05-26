#include "shell.h"

/**
 * bfree - frees a pointer and null the adress
 * @ptr: adress of the pointer to free
 *
 * Return: 1 if it freed, 0 otherwise.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
