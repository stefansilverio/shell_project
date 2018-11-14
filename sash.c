#include "sash.h"

/**
 * main - the driver function for our sash shell
 *
 * Return: Always 0
 */

int main(void)
{
	char *line, *path, *dir;
	char **commands, **dirs;
	struct stat buffer;

	signal(SIGINT, SIG_IGN);  /* Ignores Ctrl+C signal to quit shell */

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2); /* Write command prompt to stdout */
		line = read_line(); /* Stores command written in line */
		commands = split_line(line); /* Parses the line into individual words */
		if (run_builtin(commands) == -1) /* Looks for builtin */
		{
			if (stat(commands[0], &buffer) != 0)
			{
			    path = get_path(environ);
			    dirs = tokenize_path(path);
			    dir = find_dir(dirs, commands[0]);
			    commands[0] = dir;
			}
			_execute(commands); /* Executes the commands given */
		}
	}
	free(line);
	free(commands);
	return (0);
}
