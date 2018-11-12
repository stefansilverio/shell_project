#include "sash.h"

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
	tokenarr = malloc(sizeof(char *) * (count + 2));
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
