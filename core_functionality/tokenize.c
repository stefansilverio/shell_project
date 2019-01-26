#include "sash.h"

/**
 * tokenize_path - Splits the PATH into individual strings/tokens
 * @path: The path to be split up
 *
 * Return: Pointer to 2D array of the tokenized path
 */

char **tokenize_path(char *path)
{
	char *token = NULL;
	char *delim = ":";
	char **buf_dir = NULL;
	int idx = 0;
	int count = 0;

	while (path[idx])
	{
		if (path[idx] == *delim)
			count++;
		idx++;
	}
	buf_dir = malloc(sizeof(char *) * (count + 2));
	idx = 0;
	token = strtok(path, delim);
	while (token)
	{
		buf_dir[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	buf_dir[idx] = NULL;

	return (buf_dir);
}
