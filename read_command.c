#include "sash.h"

/**
 * read_line - Reads a line given to the standard input & stores it in a buffer
 *
 * Return: A pointer to the stored string
 */
char *read_line()
{
	char *str = NULL;
	size_t size = 0;
	size_t length = 0;

	length = getline(&str, &size, stdin);
	if ((int)length == -1)
	{
		write(1, "I'm leaving...connection closed\n", 32);
		exit(0);
	}
	if (str[length - 1] == '\n')
		str[length - 1] = '\0';

	return (str);
}
