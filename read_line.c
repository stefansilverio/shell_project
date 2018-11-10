#include "sash.h"

/**
 * read_line - Reads a line given to the standard input and stores it in a buffer
 *
 * Return: A pointer to the stored string
 */

char *read_line()
{
	char *str = NULL;
	ssize_t size = 0;

	getline(&str, &size, stdin);

	return(str);
}
