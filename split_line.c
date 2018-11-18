#include "sash.h"

/**
 * split_line - Splits the command given to sash into individual strings/tokens
 *
 * @line: The line to be split up
 *
 * Return: A pointer to an array of strings/tokens split up by the function
 */

char **split_line(char *line, char **av)
{
	int idx = 0;
	int count = 0;
	char *token = NULL;
	char delim[2] = {' ', ';'};

	while (line[idx])
	{
		if (line[idx] == ' ')
			count++;
		idx++;
	}
	av = malloc(sizeof(*av) * (count + 2));
	if (av == NULL)
	{
		free(line);
		return(NULL);
	}
	idx = 0;
	token = strtok(line, delim);
	while (token)
	{
		av[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	av[idx] = NULL;
	return (av);
}
