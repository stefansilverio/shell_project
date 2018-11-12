#include "sash.h"

/**
 * read_line - Reads a line given to the standard input and stores it in a buffer
 *
 * Return: A pointer to the stored string
 */

char *read_line()
{
	char *str = NULL;
	size_t size = 0;
	int length = 0;

	length = getline(&str, &size, stdin);
	if (str[length - 1] == '\n')
		str[length - 1] = '\0';

	return(str);
}
