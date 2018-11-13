#include "sash.h"

/**
 * split_line - Splits the command given to sash into individual strings/tokens
 *
 * @line: The line to be split up
 *
 * Return: A pointer to an array of strings/tokens split up by the function
 */

char **split_line(char *line)
{
	int idx = 0;
	int count = 0;
	char *token;
	char *delim = " ";
	char **tokenarr;

	while (line[idx])
	{
		if (line[idx] == ' ')
			count++;
		idx++;
	}
	tokenarr = malloc(sizeof(char *) * (count + 1));
	idx = 0;
	token = strtok(line, delim);
	while (token)
	{
		tokenarr[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	return (tokenarr);
}
