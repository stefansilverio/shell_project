#include "sash.h"

/**
 * main - the driver function for our sash shell
 *
 * Return: Always 0
 */

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
	return (0);
}
