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
	if ((str == NULL) || (length < 2))
	{
		free(str);
		return (NULL);
	}
	if (length >= 2)
	{
		if (str[length - 1] == '\n')
			str[length - 1] = '\0';
	}	
	if ((int)length == EOF)
	{
		write(1, "Bye bye\n", 8);
		exit(0);
	}
	return (str);
}
