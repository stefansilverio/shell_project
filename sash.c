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

/*	signal(SIGINT, SIG_IGN); /* Ignores Ctrl+C signal to quit shell */ /* todo - UNCOMMENT OUT WHEN CTRL+D/exit is figured out */

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Write command prompt to stdout */
		line = read_line(); /* Stores command written in line */
		commands = split_line(line); /* Parses the line into individual words */
		_execute(commands); /* Executes the commands given */
	}
	free(line);
	free(commands);
	return (0);
}
