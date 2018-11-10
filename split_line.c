#include "sash.h"

char **split_line(char *line)
{
	int index = 0, length;
	char *token;
	char **tokenarr;
	char *delim = " ";

	token = strtok(line, delim);

	while (token)
	{
		for (length = 0; token[length]; length++)
			;
		tokenarr = malloc((length + 1) * sizeof(char));
		tokenarr[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	return(tokenarr);
}
