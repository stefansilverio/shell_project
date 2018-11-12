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
		write(STDOUT_FILENO, "$ ", 2);
		line = read_line();
		commands = split_line(line);
		_execute(commands);
	}
	free(line);
	free(commands);
	return (0);
}
