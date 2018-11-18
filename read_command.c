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
	ssize_t length = 0;

	while ((length = getline(&str, &size, stdin)) != EOF)
	{
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
		return (str);
	}
	free(str);
	if (isatty(STDIN_FILENO))
	    printf("logout\n");
	_exit(0);
}
