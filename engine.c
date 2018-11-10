#include "sash.h"

int main(void)
{
	char *line;
	char **commands;

	while (1)
	{
		printf("$ ");
		line = read_line();
		commands = split_line(line);
	}
	free(line);
	free(commands);
}
