#include "sash.h"

/**
 * _calloc - allocate memory for an array
 *
 * @nmemb: number of elements in the array
 *
 * @size: size of each element
 *
 * Return: Always 0
 */
void *_calloc(unsigned int nmemb, size_t size)
{
	char *buffer;
	int buf_size = nmemb * size;
	int index = 0;

	buffer = malloc(buf_size);

	if (buffer == NULL)
		return (NULL);

	while (buf_size--)
	{
		buffer[index] = 0;
		index++;
	}

	buffer = (void *)buffer;

	return (buffer);
}
